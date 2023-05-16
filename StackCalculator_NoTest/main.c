// 202201543 최경민

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ABS(X) ((X) < 0 ? -(X) : (X))
#define EPSILON 0.000001
#define IS_OPERATOR(c) c == '+' || c == '-' || c == '*' || c == '/'
#define IS_NUMERIC(c) '0' <= c &&c <= '9'

/**
프로그램에서 사용되는 각종 에러 메세지를 출력하는 함수
@param message 출력할 메세지
*/
void printError(char *message)
{
  fprintf(stderr, "%s", message);
  exit(1);
}

typedef double element;
typedef struct StackNode
{
  element data;
  struct StackNode *link;
} StackNode;

typedef struct
{
  StackNode *top;
} LinkedStackType;

/**
스택 초기화 함수
@param s 초기화할 스택
 */
void init(LinkedStackType *s)
{
  s->top = NULL;
}

/**
스택이 비어있는지 확인하는 함수
@param s 확인할 스택
@return 스택이 비어있으면 1, 아니면 0 반환
*/
int is_empty(LinkedStackType *s)
{
  return (s->top == NULL);
}

/**
스택이 포화 상태인지 확인하는 함수
@param s 확인할 스택
@return 스택이 포화 상태이면 1, 아니면 0 반환
*/
int is_full(LinkedStackType *s)
{
  return 0;
}

/**
스택에 데이터를 삽입하는 함수
@param s 데이터를 삽입할 스택
@param item 스택에 삽입할 데이터
*/
void push(LinkedStackType *s, element item)
{

  StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
  temp->data = item;
  temp->link = s->top;
  s->top = temp;
}

/**
스택의 맨 위에 있는 데이터를 반환하는 함수
@param s 맨 위에 있는 데이터를 반환할 스택
@return 스택의 맨 위에 있는 데이터
*/
element peek(LinkedStackType *s)
{
  return s->top->data;
}

/**
스택에 저장된 데이터를 출력하는 함수
@param s 출력할 스택
*/
void print_stack(LinkedStackType *s)
{
  for (StackNode *p = s->top; p != NULL; p = p->link)
    printf("%f->", p->data);
  printf("NULL \n");
}

/**
스택에서 데이터를 제거하고 반환하는 함수
@param s 데이터를 제거할 스택
@return 제거한 데이터
*/
element pop(LinkedStackType *s)
{
  if (is_empty(s))
  {
    exit(1);
  }
  else
  {

    StackNode *temp = s->top;
    element data = temp->data;
    s->top = s->top->link;
    free(temp);
    return data;
  }
}

/**
주어진 문자가 여는 괄호인지 확인하는 함수
@param c 확인할 문자
@return 여는 괄호면 1, 아니면 0 반환
*/
int isOpeningBracket(char c)
{
  return c == '(' || c == '[' || c == '{';
}

/**
주어진 문자가 닫는 괄호인지 확인하는 함수
@param c 확인할 문자
@return 닫는 괄호면 1, 아니면 0 반환
*/
int isClosingBracket(char c)
{
  return c == ')' || c == ']' || c == '}';
}


/**
주어진 문자가 올바른 닫는 괄호인지 확인하는 함수
@param open 해당하는 여는 괄호
@param close 확인할 닫는 괄호
@return 올바른 닫는 괄호이면 1, 아니면 0 반환
*/
int isRightBrackets(char open, char close)
{
  return (open == '(' && close != ')') ||
         (open == '[' && close != ']') || (open == '{' && close != '}');
}

/**

주어진 문자가 유효한 문자인지 확인하는 함수
@param c 확인할 문자
@return 유효한 문자이면 1, 아니면 0 반환
*/
int isAllowedCharacter(char c)
{
  return IS_OPERATOR(c) || IS_NUMERIC(c) || c == '.' || c == ' ';
}

/**

문자열에 문자를 추가하는 함수
@param {char *} dst - 추가할 대상 문자열
@param {char} c - 추가할 문자
@returns {void}
*/
void append(char *dst, char c)
{
  char *p = dst;
  while (*p != '\0')
    p++; // 문자열 끝 탐색
  *p = c;
  *(++p) = '\0';
}

/**

스택의 메모리를 해제하고 top 포인터를 NULL로 만드는 함수
@param {LinkedStackType *} s - 메모리를 해제할 스택
@returns {void}
*/
void cleanStack(LinkedStackType *s)
{
  StackNode *p = s->top;
  while (p != NULL)
  {
    StackNode *next = p->link;
    free(p);  // 할당해제
    p = next; // 다음요소를 새로운 p로 지정.
  }
}

/**
후위 표기식을 계산하여 결과값을 반환하는 함수
@param {char *} postfixExp - 계산할 후위 표기식
@returns {double} - 계산 결과값
*/
double eval(char *postfixExp)
{
  int i = 0;
  double op1, op2, value = 0;
  int len = strlen(postfixExp);
  char ch;
  LinkedStackType s;
  init(&s);

  for (i = 0; i < len; i++)
  {
    ch = postfixExp[i];
    if (ch == ' ')
      continue;
      if (!(IS_OPERATOR(ch)))
      {
          // Read the whole number and push it onto the stack
           char numStr[50];
           int j = 0;
           while (i < len && (IS_NUMERIC(postfixExp[i]) || postfixExp[i] == '.'))
           {
             numStr[j++] = postfixExp[i++];
           }
           numStr[j] = '\0';
           value = atof(numStr);
           push(&s, value);
           i--; // 한칸 뒤로 이도
      }
      
    else
    { // 연산자이면 피연산자를 스택에서 꺼내기

      op2 = pop(&s);
      op1 = pop(&s);
      switch (ch)
      { // 연산을 수행하고 스택에 저장
      case '+':
        push(&s, op1 + op2);
        break;
      case '-':
        push(&s, op1 - op2);
        break;
      case '*':
        push(&s, op1 * op2);
        break;
      case '/':
        push(&s, op1 / op2);
        break;
      }
    }
  }

  element res = pop(&s);
  cleanStack(&s);
  return res;
}

/**
연산자 우선순위를 반환하는 함수
@param {char} op - 우선순위를 찾을 연산자
@returns {int} - 연산자의 우선순위
*/
int getOperationOrder(char op)
{
  switch (op)
  {
  case '(':
  case ')':
    return 0;
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  }
  printError("잘못된 연산자가 식에 포함되어 있습니다.");
  return -999;
}

/**

문자열을 역순으로 뒤집는 함수
@param {char *} postfixExp - 뒤집을 문자열
@returns {char *} - 역순으로 뒤집은 문자열
*/
char *reverse_exp(char *postfixExp)
{
  char *res = (char *)malloc(sizeof(char) * strlen(postfixExp));
  LinkedStackType s;
  init(&s);

  // 스택에 넣고
  for (int i = 0; i < strlen(postfixExp); i++)
  {
    push(&s, postfixExp[i]);
  }
  // 빼면서 문자열에 append
  for (int i = 0; i < strlen(postfixExp); i++)
  {
    append(res, pop(&s));
  }
  return res;
}

/**

중위 표기식을 전위 표기식으로 변환하는 함수
@param {char *} infixExp - 변환할 중위 표기식
@returns {char *} - 변환된 전위 표기식
*/
char *infix_to_prefix(char *infixExp)
{
  char ch, e;
  int i = 0, j = 0, len = strlen(infixExp);
  char *prefixExp = (char *)malloc(sizeof(char) * (len + 1));
  LinkedStackType s;
  init(&s);
  for (i = len - 1; i >= 0; i--)
  {
    ch = infixExp[i];
    if ((IS_NUMERIC(ch)) || ch == '.')
    {
      append(prefixExp, ch);
    }
    else if (ch == ')')
    {
      push(&s, ch);
    }
    else if (IS_OPERATOR(ch))
    {
      while (!is_empty(&s) && getOperationOrder(ch) < getOperationOrder(peek(&s)))
      {
        e = pop(&s);
        append(prefixExp, ' ');
        append(prefixExp, e);
      }
      append(prefixExp, ' ');
      push(&s, ch);
    }
    else if (ch == '(')
    {
      while (!is_empty(&s) && peek(&s) != ')')
      {
        e = pop(&s);
        append(prefixExp, ' ');
        append(prefixExp, e);
      }

      if (!is_empty(&s) && peek(&s) == ')')
        pop(&s);
    }
  }
  while (!is_empty(&s))
  {
    e = pop(&s);
    append(prefixExp, ' ');
    append(prefixExp, e);
  }

  return reverse_exp(prefixExp);
}

/**

중위 표기식을 후위 표기식으로 변환하는 함수
@param {char *} infixExp - 변환할 중위 표기식
@returns {char *} - 변환된 후위 표기식
*/
char *infix_to_postfix(char *infixExp)
{
  char *res = (char *)malloc(sizeof(char) * 100);
  LinkedStackType s;
  init(&s);
  char c;
  for (int i = 0; i < strlen(infixExp); i++)
  {
    c = infixExp[i];
    if (IS_OPERATOR(c)) // 연산자면
    {
      while (!is_empty(&s) && getOperationOrder(peek(&s)) >= getOperationOrder(c)) // 스택이 비어있지 않고 연산 순위가 문자와 같거나 우선이면
      {
        append(res, ' ');     // res에 공백 append
        append(res, pop(&s)); // 스택에서 꺼내 res에 append
      }
      append(res, ' ');
      push(&s, c); // 스택에 문자 push
    }
    else
    {
      switch (c)
      {
      case '(':
      {
        push(&s, c);
        break;
      }
      case ')':
      {
        int e = pop(&s);
        append(res, ' ');
        while (e != '(')
        {
          append(res, e);
          e = pop(&s);
        }
        break;
      }
      default:
      {
        append(res, c);
        break;
      }
      }
    }
  }
  while (!is_empty(&s))
  {
    append(res, ' ');
    append(res, pop(&s));
  }
  cleanStack(&s);

  return res;
}

/**

주어진 수식이 올바른지 검증하는 함수
@param {char *} exp - 검증할 수식 문자열
@returns {number} - 검증 결과 (1: 올바른 수식, 0: 잘못된 수식)
*/
int isValidExp(char *exp)
{
  LinkedStackType s;
  init(&s);
  char ch, open_ch;
  int isPrevOperator = 0;

  for (int i = 0; i < strlen(exp); i++)
  {
    ch = exp[i];
    // 이전 문자가 연산자고 또 연산자면
    if (isPrevOperator && (IS_OPERATOR(ch)))
      return 0;
    if (isOpeningBracket(ch))
    {
      push(&s, ch);
    }
    else if (isClosingBracket(ch))
    {
      if (is_empty(&s))
      {
        cleanStack(&s);
        return 0;
      }
      else
      {
        open_ch = pop(&s);
        if (isRightBrackets(open_ch, ch))
        {
          cleanStack(&s);
          return 0;
        }
      }
    }
    else if (!(IS_OPERATOR(ch)) && !(IS_NUMERIC(ch)) && ch != ' ' && ch != '\0' && ch != '.')
    {
      cleanStack(&s);
      return 0;
    } // 연산자도 숫자도 공백도 널문자도 아니면 오류
    isPrevOperator = IS_OPERATOR(ch);
  }

  cleanStack(&s);
  if (!is_empty(&s))
    return 0; // 스택에 남아있으면 오류
  return 1;
}


/**
주어진 문자열에서 공백을 제거하는 함수
@param {char *} exp - 공백을 제거할 문자열
@returns {char *} - 공백이 제거된 문자열
*/
char *trim(char *exp) // 공백제거
{
  char *res = (char *)malloc(sizeof(char) * 100);
  for (int i = 0; i < strlen(exp); i++)
  {
    if (exp[i] != ' ')
      append(res, exp[i]);
  }
  return res;
}

int main() {
    
        char *infixExp = malloc(sizeof(char) * 100);
        printf("중위식을 입력하세요: ");
        scanf("%[^\n]s", infixExp);       // Regex로 개행문자를 제외하고 읽어오기
        char *trimedExp = trim(infixExp); // 공백 제거해 깨끗한 문자열로 만들기
        if (!isValidExp(trimedExp))
        {
          printf("올바르지 않은 식입니다.");
          exit(1);
        }

        printf("\n전위식: %s\n", infix_to_prefix(trimedExp));
        char *postfixExp = infix_to_postfix(trimedExp);
        printf("후위식: %s\n", postfixExp);
        printf("계산결과: %f\n", eval(postfixExp));
    

}
