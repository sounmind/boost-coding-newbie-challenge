// ���Ḯ��Ʈ�� Stack �����
#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
    int data;
    struct stackNode* next;
} StackNode;

StackNode* createStackNode(int data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(StackNode* root) {
    return !root;
}

void push(StackNode** root, int data) {

    if(isEmpty(*root)) {
        printf("stack is EMPTY...");
        *root = createStackNode(data);
    } else {
        StackNode *newNode = createStackNode(data); // ������ ����� �� ��� ����
        newNode -> next = *root;                    // �� ��尡 �ֱٿ� �߰��� ��带 ����Ŵ
        *root  = newNode;                           // root�� �� ��带 ����Ŵ
    }
    printf("%d pushed to stack\n", data);
}

int pop(StackNode** root) {
    if (isEmpty(*root)) {
        printf("stack is EMPTY...");
        return -9999;
    }
    StackNode * temp;
    temp = *root;               // ������ ����� �ּ� ���� �ӽ÷� ����
    int popped = (*root)->data; // ������ ����� �����͸� ����
    *root = (*root)->next;      // ������ ����� ���� ��带 root�� ����Ŵ
    free(temp);                 // ���� root�� ����Ű�� ��� ����
return popped;
}

int peek(StackNode** root) {
    if (isEmpty(*root)) {
        printf("stack is EMPTY...");
        return -9999;
    }
    return (*root)->data;
}

int main() {
    StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    push(&root, 40);

    printf("%d pop from stack\n", pop(&root)); // 40
    printf("%d pop from stack\n", pop(&root)); // 30

    push(&root, 50);
    printf("%d peeked from stack\n", peek(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    return 0;
}
/*
Main �Լ��� �����Ű�� Stack ��� ����� ���������� ���;� �մϴ�. �迭�� ���Ḯ��Ʈ�� �̿��ؼ� ������ �� ���̴µ���,
� ���� �� ������ ��̳���? Main �Լ��� ������ ������ ���鼭 ���赵 �غ��ð�, 
Stack �� ������ �� ����Ʈ�� ����� ��İ� �迭�� ����� ��� �� � ����� �� ���Ҵ��� ���� ���� ������ �ּ���! 
*/