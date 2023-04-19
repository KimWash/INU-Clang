#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Todo: 부호체크


#define ABS(X) ((X) < 0 ? -(X) : (X))
#define EPSILON 0.000001
#define IS_OPERATOR(c) c == '+' || c == '-' || c == '*' || c == '/'
#define IS_NUMERIC(c) '0' <= c &&c <= '9'

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

// 초기화 함수
void init(LinkedStackType *s)
{
  s->top = NULL;
}

// 공백 상태 검출 함수
int is_empty(LinkedStackType *s)
{
  return (s->top == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedStackType *s)
{
  return 0;
}
// 삽입 함수
void push(LinkedStackType *s, element item)
{

  StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
  temp->data = item;
  temp->link = s->top;
  s->top = temp;
}

element peek(LinkedStackType *s)
{
  return s->top->data;
}

void print_stack(LinkedStackType *s)
{
  for (StackNode *p = s->top; p != NULL; p = p->link)
    printf("%f->", p->data);
  printf("NULL \n");
}

// 삭제 함수
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

int isOpeningBracket(char c)
{
  return c == '(' || c == '[' || c == '{';
}
int isClosingBracket(char c)
{
  return c == ')' || c == ']' || c == '}';
}

int isRightBrackets(char open, char close)
{
  return (open == '(' && close != ')') ||
         (open == '[' && close != ']') || (open == '{' && close != '}');
}

int isAllowedCharacter(char c)
{
  return IS_OPERATOR(c) || IS_NUMERIC(c) || c == '.' || c == ' ';
}

double charSeqToDouble(char *chSeq)
{
  int pointIndex = -999;
  int len = strlen(chSeq);
  double front, back = 0.0;
  for (int i = 0; i < len; i++)
  {
    char ch = chSeq[i];
    if (!isAllowedCharacter(ch))
      printError("허용되지 않은 문자가 식에 포함되어 있습니다.");
    // 점을 만나면
    if (ch == '.')
    {
      pointIndex = i;
      break;
    }
    int intPart = (ch - '0'); // 정수부 선언
    for (int j = 0; j < i; j++)
    {                // 10을 i번 곱해 자리수 맞춰주기.
      intPart *= 10; // 다음 문자 더하기
    }
    front += intPart;
  }
  // 소수점을 못찾으면 정수부만 반환
  if (pointIndex == -999)
  {
    return front;
  }
  for (int i = pointIndex + 1; i < len; i++)
  {
    char ch = chSeq[i];
    if (!isAllowedCharacter(ch))
      printError("허용되지 않은 문자가 식에 포함되어 있습니다.");
    int fractional = (ch - '0'); // 정수부 선언
    for (int j = 0; j < (len - i - 1); j++)
    { // 10을 i번 곱해 자리수 맞춰주기.
      fractional *= 10;
    }
    back += fractional;
  }
  while (back > 1)
    back /= 10;
  return front + back;
}

void append(char *dst, char c)
{
  char *p = dst;
  while (*p != '\0')
    p++; // 문자열 끝 탐색
  *p = c;
  *(++p) = '\0';
}

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
           i--; // Move the index back by 1 since we advanced it by 1 in the loop
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



typedef struct  {
    char infixExp[100];
    char prefixExp[100];
    char postfixExp[100];
    double result;
}TestCase;

int run(TestCase testCase) {
    char *trimedExp = trim(testCase.infixExp); // 공백 제거해 깨끗한 문자열로 만들기
    if (!isValidExp(trimedExp))
    {
      printf("올바르지 않은 식입니다.");
      exit(1);
    }
  
    char *prefixExp = infix_to_prefix(trimedExp);
    printf("\n전위 표기식: %s\n", prefixExp);
    char *postfixExp = infix_to_postfix(trimedExp);
    printf("후위 표기식: %s\n", postfixExp);
    double res = eval(postfixExp);
    printf("%f\n", res);
    
    
    float fval = res;



    if (strcmp(trim(prefixExp), trim(testCase.prefixExp))) return 0;
    if (strcmp(trim(postfixExp), trim(testCase.postfixExp))) return 0;
    if (ABS(fval - testCase.result) >= EPSILON) return 0;
    return 1;
}


void test(){
    TestCase case1 = {"3 + 7 * 2 - 4 / 2 + 5 - 9 * 2 + 8", "+ - + - + 3 * 7 2 / 4 2 5 * 9 2 8", "3 7 2 * + 4 2 / - 5 + 9 2 * - 8 +", 10};
    TestCase case2 = {"(6 + 2) * 5 - 12 / 4 + (9 - 3) * 2 - 8 / 2", "- + - * + 6 2 5 / 12 4 * - 9 3 2 / 8 2", "6 2 + 5 * 12 4 / - 9 3 - 2 * + 8 2 / -", 45};
    TestCase case3 = {"(9 - (5 + 3) * 2) + ((4 * 3) - (2 * 5)) / (3 - 1)", "+ - 9 * + 5 3 2 / - * 4 3 * 2 5 - 3 1", "9 5 3 + 2 * - 4 3 * 2 5 * - 3 1 - / +", -6};
    TestCase case4 = {"((2.5 + 1.5) * 3 - 4) / 2.2 + 1.8", "+/-*+2.5 1.5 3 4 2.2 1.8", "2.5 1.5+ 3 * 4- 2.2 / 1.8+", 5.436364};
    TestCase case5 = {"6 - 2 * (4.5 - 1.5) / (3 + 1)", "-6 /* 2 -4.5 1.5 +3 1", "6 2 4.5 1.5- * 3 1+/-", 4.5};
    TestCase case6 = {"(1.2 + 2.3) * ((4.5 - 2) / 2) - 3.4", "-*+1.2 2.3 /-4.5 2 2 3.4", "1.2 2.3+ 4.5 2- 2/ * 3.4-", 0.975};
 
    
    printf("case 1: %s\n", run(case1) ? "성공" : "실패");
    printf("case 2: %s\n", run(case2) ? "성공" : "실패");
    printf("case 3: %s\n", run(case3) ? "성공" : "실패");
    printf("case 4: %s\n", run(case4) ? "성공" : "실패");
    printf("case 5: %s\n", run(case5) ? "성공" : "실패");
    printf("case 6: %s\n", run(case6) ? "성공" : "실패");
    
}

void user() {
    char *infixExp = malloc(sizeof(char) * 100);
    printf("중위 표기식을 입력하세요: ");
    scanf("%[^\n]s", infixExp);       // Regex로 개행문자를 제외하고 읽어오기
    char *trimedExp = trim(infixExp); // 공백 제거해 깨끗한 문자열로 만들기
    if (!isValidExp(trimedExp))
    {
      printf("올바르지 않은 식입니다.");
      exit(1);
    }

    printf("\n전위 표기식: %s\n", infix_to_prefix(trimedExp));
    char *postfixExp = infix_to_postfix(trimedExp);
    printf("후위 표기식: %s\n", postfixExp);
    printf("%f\n", eval(postfixExp));
}

int main()
{
//    user();
    test();
}
