#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 1

typedef int element;
typedef struct {
   int front, rear;
   int count;
   element *data;
   int capacity;
} QueueType;

//오류 함수
void error(char* message)
{
   fprintf(stderr, "%s\n", message);
   exit(1);
}

//초기화 함수
void init_queue(QueueType* q)
{
   q->front = q->rear = q->count = 0;
   q->data = (element*)malloc(sizeof(element));
   q->capacity = MAX_QUEUE_SIZE;
}

//공백 상태 검출 함수
int is_empty(QueueType* q)
{
   return (q->count == 0);
}

//포화 상태 검출 함수
int is_full(QueueType* q)
{
   return (q->count == q->capacity - 1);
}

//원형큐 출력 함수
void queue_print(QueueType* q) {
   printf("QUEQUE(front=%d, rear=%d, count=%d) = ", q->front, q->rear, q->count);
   if (!is_empty(q)) {
      int i = q->front;
      do {
         i = (i + 1) % ( q->capacity);
         printf("%d | ", q->data[i]);
         if (i == q->rear)
            break;
      } while (i != q->front);
   }
   printf("\n");
}

//큐가 가득찼을 시 2배 해주는 함수
void resize(QueueType* q)
{
   q->capacity *= 2; // capacity 2 times
   q->data = (element*)realloc(q->data, sizeof(element) * q->capacity);
}

//삽입 함수
void enqueue(QueueType* q, element item)
{
   if (is_full(q)) {
      resize(q);
   }
   q->rear = (q->rear + 1) % q->capacity;
   q->data[q->rear] = item;
   q->count++;
}

//삭제 함수
element dequeue(QueueType* q)
{
   if (is_empty(q))
      printf("큐가 공백상태입니다.");
   q->count--;
   q->front = (q->front + 1) % q->capacity;
   return q->data[q->front];
}

//삭제 함수
element peek(QueueType* q)
{
   if (is_empty(q))
      error("큐가 공백상태입니다.");
   return q->data[q->front + 1] % q->capacity;
}


int main(void)
{
   QueueType queue;
   int element;

   init_queue(&queue);
   printf("--데이터 추가 단계--\n");
   for(int i = 0; i < 100; i++)
   {
      enqueue(&queue, i);
      queue_print(&queue);

   }
}
