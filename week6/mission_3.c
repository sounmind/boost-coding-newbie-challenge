// �迭�� Queue �����

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
    queue->rear = capacity-1; // �� �����ڴ� �̷��� ����������? ó�� ���� ���� �� rear�� 1�� �������Ѿ� �ϴµ�, rear�� 0�̸� �迭 �� �ڸ��� ��?
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
    if(queue->rear == (queue->capacity)-1) {        // rear�� �迭�� ���̶��
        queue->rear = 0;
    } else {
        (queue->rear)++;
    }
    *((queue->array)+(queue->rear)) = item;         // ������ �������� �迭�� �� �ֱ�
    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is EMPTY ... ");
        return -9999;
    }
    int item = *((queue->array)+(queue->front));    // ������ �������� �迭 �� ���ϱ�
    
    (queue->size)--;
    if(queue->front == (queue->capacity)-1) {       // front�� �迭�� ���̶��
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