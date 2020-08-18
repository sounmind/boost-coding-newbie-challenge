// 연결리스트 응용: 뒤에서 k번째 노드를 출력하도록 
// append, getKthNodeFromLast, printList 함수 작성

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void append(Node** head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;     // 새로운 노드에 데이터 삽입
    newNode -> next = *head;    // 새로운 노드가 head가 가리키는 것을 가리킴
    *head = newNode;            // head가 새로운 노드를 가리킴
    printf("%d is appended\n", data);
    return;
}

int getKthNodeFromLast (Node* head, int k) {
    Node* pointer = head;           // 임시 포인터 변수가 head가 가리키는 것을 가리킴
    int count = 0;
    int KthData = 9999;
    while(1) {
        count++;
        if(count == k) {            // k번째 일 때 임시 포인터 변수가 가리키는 노드의 값을 반환
            return pointer -> data;
        }
        pointer = pointer -> next;  // 임시 포인터 변수가 다음 노드를 가리킴
    }
    return KthData;
}

void printReverse(Node* head) {     // 연결리스트를 거꾸로 출력하는 재귀 함수
    if(head == NULL) {
        return;
    }
    printReverse(head -> next);
    printf("%d ", head -> data);
}

int main() {
    Node* head = NULL;              // head에 메모리 할당 필요없음. 이중포인터 매개변수로 전달

    append(&head, 9);
    append(&head, 8);
    append(&head, 4);
    append(&head, 14);
    append(&head, 5);

    printReverse(head);

    printf("\n%dth last node is %d\n", 2, getKthNodeFromLast(head, 2));
}