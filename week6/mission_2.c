// 연결리스트로 Stack 만들기
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
        StackNode *newNode = createStackNode(data); // 데이터 저장된 새 노드 생성
        newNode -> next = *root;                    // 새 노드가 최근에 추가된 노드를 가리킴
        *root  = newNode;                           // root가 새 노드를 가리킴
    }
    printf("%d pushed to stack\n", data);
}

int pop(StackNode** root) {
    if (isEmpty(*root)) {
        printf("stack is EMPTY...");
        return -9999;
    }
    StackNode * temp;
    temp = *root;               // 삭제할 노드의 주소 값을 임시로 저장
    int popped = (*root)->data; // 삭제할 노드의 데이터를 저장
    *root = (*root)->next;      // 삭제할 노드의 다음 노드를 root가 가리킴
    free(temp);                 // 원래 root가 가리키던 노드 삭제
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
Main 함수를 실행시키면 Stack 출력 결과가 정상적으로 나와야 합니다. 배열과 연결리스트를 이용해서 구현을 해 보셨는데요,
어떤 것이 더 마음에 드셨나요? Main 함수의 내용을 수정해 보면서 실험도 해보시고, 
Stack 을 구현할 때 리스트를 사용한 방식과 배열을 사용한 방식 중 어떤 방식이 더 좋았는지 느낀 점도 공유해 주세요! 
*/