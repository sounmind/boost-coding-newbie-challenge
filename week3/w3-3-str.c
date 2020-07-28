/*
제목: 문자열이 입력되는, 배열을 이용한 원형 큐 구현,

(개선된) 원형 큐
큐가 텅 비었을 때
    front와 rear가 같은 위치를 가리킨다.
큐에 데이터를 넣을 때
    rear를 다음 위치로 이동시킨 뒤 그곳에 데이터를 저장한다.
큐에서 데이터를 뺄 때
    front를 다음 위치로 옮긴다음, 그 위치에 있는 값을 반환한다.
큐가 꽉 찼을 때
    rear가 가리키는 위치의 다음 위치를 front가 가리킨다.
*/

#define _CRT_SECURE_NO_WARNINGS
#define QUEUE_LENGTH 10 + 1 // 배열 길이가 N이라면, N-1개 데이터가 채워졌을 때 꽉찬 것으로 간주
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct circularQueue // 원형 큐 자료형 구조체 선언
{
    int front; // 큐의 머리
    int rear; // 큐의 꼬리
    char *queueArray[QUEUE_LENGTH]; // 큐의 포인터(변수로 이뤄진) 배열
} Queue;

void queueInit(Queue* pointerQueue);
int isQueueEmpty(Queue* pointerQueue);
int queueNextPositionIndex(int position);
void add(Queue* pointerQueue, char * data);
void pop(Queue* pointerQueue);
void display(Queue* pointerQueue);

int main(void) {

    Queue queue; // 큐 선언
    queueInit(&queue); // 큐 초기화

    char order[100];

    while (1)
    {
        printf(">>>>>>>>>>>>>>>>>>>> 명령 번호를 입력하세요\n");
        printf(">>>> add(1), pop(2), display(3), quit(4) : ");
        scanf("%s", &order);

        if (strlen(order) > 1) { printf("\n>>>> 명령이 너무 깁니다!\n\n"); continue; }                // 예외1) 입력 문자가 두 자리 이상이면 continue;
        if (atoi(order) == 0) { printf("\n>>>> 명령이 해당 숫자(1~4)가 아닙니다!\n\n"); continue; }    // 예외2) 입력 문자가 숫자가 아니면 continue;

        switch (atoi(order)) {
        case 1: // add
        {
            char *inputContents = malloc(sizeof(char)*100);                                         // 큐에 입력할 배열을 위해 충분한 크기로 메모리 할당

            printf(">>>> 추가할 내용을 입력하세요 :            ");
            scanf("%s", inputContents);

            add(&queue, inputContents);
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
            printf("\n>>>> 프로그램을 종료합니다.\n");
            return 0;
        }
        default: // 예외3) '한 자리'에다가 '숫자'이지만 해당 범위(1~4)가 아닌 경우
        {
            printf("\n>>>> 다시 제대로 명령 번호를 입력해주세요.\n\n");
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
    { return 1; }
    else
    { return 0; }
}

int queueNextPositionIndex(int position)
{
    if (position == QUEUE_LENGTH - 1)                                       // 위치가 배열의 마지막 요소의 인덱스 값이라면
    { return 0; }
    else
    { return position + 1; }
}

void add(Queue* pointerQueue, char * data)
{
    if (queueNextPositionIndex(pointerQueue->rear) == pointerQueue->front)  // 큐가 꽉 찼다면, (rear가 가리키는 곳의 다음 위치가 front가 가리키는 곳)
    {
        printf("\n큐가 꽉 찼습니다!\n\n");
        return;
    }
    pointerQueue->rear = queueNextPositionIndex(pointerQueue->rear);        // rear를 한 칸 이동
    pointerQueue->queueArray[pointerQueue->rear] = data;                    // rear가 가리키는 곳에 데이터 저장

    printf("\n정상 입력되었습니다...\n\n");
    return;
}

void pop(Queue* pointerQueue)
{
    if (isQueueEmpty(pointerQueue))
    {
        printf("\n큐가 텅 비었습니다!\n\n");
        return;
    }

    pointerQueue->front = queueNextPositionIndex(pointerQueue->front);                                  // front를 한 칸 이동
    printf("\n>>>>>>>> Pop Executed: \" %s \"\n\n", pointerQueue->queueArray[pointerQueue->front]);     // front가 가리키는 데이터 반환

}

void display(Queue* pointerQueue)
{
    if (isQueueEmpty(pointerQueue))
    {
        printf("\n큐가 텅 비었습니다!\n\n");
        return;
    }

    printf("\n>>>>>>>> Queue Start <<<<<<<<\n\n");
    int i = pointerQueue->front;

    while (1)
    {
        i = queueNextPositionIndex(i); // 다음 위치로 이동

        printf("index= %d, value= %s \n", i, pointerQueue->queueArray[i]); // 해당 위치에 있는 값 출력

        if (pointerQueue->rear == i) // 해당 위치가 rear가 가리키는 위치면 함수 종료
        {
            printf("\n>>>>>>>> Queue  End  <<<<<<<<\n\n");
            return;
        }
    }
}
