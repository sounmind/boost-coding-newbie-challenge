// 이 버전에서는 큐에 문자열이 입력될 수 있도록 합니다.

#define _CRT_SECURE_NO_WARNINGS
#define QUEUE_LENGTH 10 + 1 // 배열 길이가 N이라면, N-1개 데이터가 채워졌을 때 꽉찬 것으로 간주
#include <stdio.h>
#include <stdlib.h>

typedef struct circularQueue // 원형 큐 자료형 구조체 선언
{
    int front; // 큐의 머리
    int rear; // 큐의 꼬리
    char *queueArray[QUEUE_LENGTH];
} Queue;

void queueInit(Queue* pointerQueue);
int isQueueEmpty(Queue* pointerQueue);
int queueNextPositionIndex(int position);
void add(Queue* pointerQueue);
void pop(Queue* pointerQueue);
void display(Queue* pointerQueue);

int main(void) {

    // Queue 생성 및 초기화
    Queue queue;
    queueInit(&queue);

    char order[100];
    // char inputContents[100];

    while (1)
    {
        printf("queue front: %i, queue rear: %i \n", queue.front, queue.rear);
        printf(">>>> 명령 번호를 입력하세요.\n");
        printf(">>>> add(1), pop(2), display(3), quit(4) : ");
        scanf("%s", &order);


        switch (atoi(order)) {
        case 1: // add
        {
            // printf(">>>> 추가할 내용을 입력하세요 : ");
            // scanf("%s", inputContents);
            add(&queue);
            break;
        }

        case 2: // pop
        {
            pop(&queue);
            break;
        }
        case 3: // display
        {
            display(&queue);
            break;
        }
        case 4: // quit
        {
            printf(">>>> 프로그램을 종료합니다.\n");
            return 0;
        }
        default:
        {
            printf(">>>> 다시 제대로 명령 번호를 입력해주세요.\n");
            break;
        }
        }
    }

    return 0;
}



void queueInit(Queue* pointerQueue)
{
    pointerQueue->front = 0;
    pointerQueue->rear = 0;
}

int isQueueEmpty(Queue* pointerQueue)
{
    if (pointerQueue->front == pointerQueue->rear)                          // 큐가 텅 비었다 == front와 rear가 동일한 위치를 가리킨다
    {
        return 1; // True 비었다
    }
    else
    {
        return 0; // False
    }
}

int queueNextPositionIndex(int position)
{
    if (position == QUEUE_LENGTH - 1)                                       // 위치가 배열의 마지막 요소의 인덱스 값이라면
        return 0;
    else
        return position + 1;
}

void add(Queue* pointerQueue)
{
    if (queueNextPositionIndex(pointerQueue->rear) == pointerQueue->front)  // 큐가 꽉 찼다면, (rear가 가리키는 곳의 다음 위치가 front가 가리키는 곳)
    {
        printf("큐가 꽉 찼습니다!\n");
        return;
    }
    pointerQueue->rear = queueNextPositionIndex(pointerQueue->rear);        // rear를 한 칸 이동

    char *inputContents = malloc(sizeof(char)*100); // 됐다!
    printf(">>>> 추가할 내용을 입력하세요 : ");
    scanf("%s", inputContents);

    //printf("pointerQueue->rear = %d\n", pointerQueue->rear); // rear 출력
    //printf("data = %s\n", data); // data 출력

    pointerQueue->queueArray[pointerQueue->rear] = inputContents;                    // rear가 가리키는 곳에 데이터 저장

    for (int i = 1; i <= pointerQueue->rear; i++) {
        printf("입력된 값 출력 %s \n", pointerQueue->queueArray[i]);
    }

    printf("정상 입력되었습니다...\n");
    return;
}

void pop(Queue* pointerQueue)
{
    if (isQueueEmpty(pointerQueue))
    {
        printf("큐가 텅 비었습니다!\n");
        return;
    }

    pointerQueue->front = queueNextPositionIndex(pointerQueue->front);                // front를 한 칸 이동
    printf(">>>> pop 실행: %s\n", pointerQueue->queueArray[pointerQueue->front]);     // front가 가리키는 데이터 반환

}

void display(Queue* pointerQueue)
{
    if (isQueueEmpty(pointerQueue))
    {
        printf("큐가 텅 비었습니다!\n");
        return;
    }

    printf("display executed: \n");
    int i = pointerQueue->front;

    while (1)
    {
        i = queueNextPositionIndex(i); // 다음 위치로 이동

        printf("index= %d, value= %s \n", i, pointerQueue->queueArray[i]); // 해당 위치에 있는 값 출력

        if (pointerQueue->rear == i) // 해당 위치가 rear가 가리키는 위치면 함수 종료
        {
            return;
        }
    }
}
