/*
배열을 이용해 스택 구현하기
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity) { // 입력된 크기만큼의 스택을 만든다.
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack -> capacity = capacity;
    stack -> top = -1; // 초기화, 스택의 가장 꼭대기를 가리키는 인덱스 값
    stack -> array = (int *)malloc(stack -> capacity*sizeof(int)); // 스택의 값이 들어갈 배열 선언
    return stack;
}

int isFull(Stack* stack) {
    // 스택의 가장 꼭대기 값(스택 배열의 인덱스값)이 스택의 용량-1과 같으면 참(1)을 리턴하고, 다르면 거짓(0)을 리턴
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
    // 이곳을 채워주세요!
    if(isEmpty(stack)) {
        printf("stack is EMPTY ");
        return -9999;
    }
    int poppedItem = stack -> array[(stack->top)--];
    return poppedItem;
}

int peek(Stack* stack) { // 가장 위에 있는 값이 무엇인지 조회만 하는 함수
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

/* 결과
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
