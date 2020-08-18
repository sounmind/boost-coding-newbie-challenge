/*
�迭�� �̿��� ���� �����ϱ�
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity) { // �Էµ� ũ�⸸ŭ�� ������ �����.
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack -> capacity = capacity;
    stack -> top = -1; // �ʱ�ȭ, ������ ���� ����⸦ ����Ű�� �ε��� ��
    stack -> array = (int *)malloc(stack -> capacity*sizeof(int)); // ������ ���� �� �迭 ����
    return stack;
}

int isFull(Stack* stack) {
    // ������ ���� ����� ��(���� �迭�� �ε�����)�� ������ �뷮-1�� ������ ��(1)�� �����ϰ�, �ٸ��� ����(0)�� ����
    return stack -> top == stack -> capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack -> top == -1;
}

void push(Stack* stack, int item) {
    if(isFull(stack)) {
        printf("stack is FULL\n");
        return;
    }
    stack -> array[++(stack -> top)] = item;
    printf("%d pushed to the stack\n", item);
}

int pop(Stack* stack) {
    // �̰��� ä���ּ���!
    if(isEmpty(stack)) {
        printf("stack is EMPTY ");
        return -9999;
    }
    int poppedItem = stack -> array[(stack->top)--];
    return poppedItem;
}

int peek(Stack* stack) { // ���� ���� �ִ� ���� �������� ��ȸ�� �ϴ� �Լ�
    if(isEmpty(stack)) {
        printf("stack is EMPTY\n");
        return -9999;
    }
    int topItem = stack->array[stack->top];
    printf("%d is top in the stack\n", topItem);
}

int main() {
    Stack* stack = createStack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    printf("%d popped from the stack\n", pop(stack));
    printf("%d popped from the stack\n", pop(stack));

    push(stack, 50);
    printf("%d popped from the stack\n", pop(stack));
    printf("%d popped from the stack\n", pop(stack));
    printf("%d popped from the stack\n", pop(stack));
    printf("%d popped from the stack\n", pop(stack));
    return 0;
}

/* ���
10 pushed to the stack
20 pushed to the stack
30 pushed to the stack
40 pushed to the stack
40 popped from the stack
30 popped from the stack
50 pushed to the stack
50 popped from the stack
20 popped from the stack
10 popped from the stack
stack is EMPTY -9999 popped from the stack
*/
