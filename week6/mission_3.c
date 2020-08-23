// 배열로 Queue 만들기

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int front;
    int rear;
    int size;
    int capacity;
    int* array;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity-1; // 왜 출제자는 이렇게 설정했을까? 처음 값을 넣을 때 rear를 1씩 증가시켜야 하는데, rear가 0이면 배열 한 자리가 비어서?
    queue->array = (int *)malloc(sizeof(int)*queue->capacity);
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is FULL ... \n");
        return;
    }
    (queue->size)++;
    if(queue->rear == (queue->capacity)-1) {        // rear가 배열의 끝이라면
        queue->rear = 0;
    } else {
        (queue->rear)++;
    }
    *((queue->array)+(queue->rear)) = item;         // 포인터 역참조로 배열에 값 넣기
    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is EMPTY ... ");
        return -9999;
    }
    int item = *((queue->array)+(queue->front));    // 포인터 역참조로 배열 값 구하기
    
    (queue->size)--;
    if(queue->front == (queue->capacity)-1) {       // front가 배열의 끝이라면
        queue->front = 0;
    } else {
        (queue->front)++;
    }

    return item;
}


int main() {
    Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("\n");

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    return 0;
}