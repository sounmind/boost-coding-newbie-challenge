// 연결리스트 응용: 뒤에서 k번째 노드를 출력하도록 
// append, getKthNodeFromLast, printList 함수 작성

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void append(Node** head, int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = data;     // 새로운 노드에 데이터 삽입
    new_node -> next = *head;    // 새로운 노드가 head가 가리키는 것을 가리킴
    *head = new_node;            // head가 새로운 노드를 가리킴
    printf("%2d is appended\n", data);
    return;
}

int get_kth_node_from_last (Node* head, int k) {
    Node* pointer = head;           // 임시 포인터 변수가 head가 가리키는 것을 가리킴
    int count = 0;
    int kth_data = 9999;
    while(1) {
        count++;
        if(count == k) {            // k번째 일 때 임시 포인터 변수가 가리키는 노드의 값을 반환
            return pointer -> data;
        }
        pointer = pointer -> next;  // 임시 포인터 변수가 다음 노드를 가리킴
    }
    return kth_data;
}

void print_reverse(Node* head) {     // 연결리스트를 거꾸로 출력하는 재귀 함수
    if(head == NULL) {
        printf("|");
        return;
    }
    print_reverse(head -> next);
    printf(" %d |", head -> data);
}

int main() {
    Node* head = NULL;              // head에 메모리 할당 필요없음. 이중포인터 매개변수로 전달

    append(&head, 9);
    append(&head, 8);
    append(&head, 4);
    append(&head, 14);
    append(&head, 5);

    print_reverse(head);

    printf("\n%dth last node is %d", 1, get_kth_node_from_last(head, 1));
    printf("\n%dth last node is %d", 2, get_kth_node_from_last(head, 2));
    printf("\n%dth last node is %d", 3, get_kth_node_from_last(head, 3));
    printf("\n%dth last node is %d", 4, get_kth_node_from_last(head, 4));
    printf("\n%dth last node is %d", 5, get_kth_node_from_last(head, 5));
}