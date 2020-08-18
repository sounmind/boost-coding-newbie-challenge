// ���Ḯ��Ʈ ����: �ڿ��� k��° ��带 ����ϵ��� 
// append, getKthNodeFromLast, printList �Լ� �ۼ�

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void append(Node** head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;     // ���ο� ��忡 ������ ����
    newNode -> next = *head;    // ���ο� ��尡 head�� ����Ű�� ���� ����Ŵ
    *head = newNode;            // head�� ���ο� ��带 ����Ŵ
    printf("%d is appended\n", data);
    return;
}

int getKthNodeFromLast (Node* head, int k) {
    Node* pointer = head;           // �ӽ� ������ ������ head�� ����Ű�� ���� ����Ŵ
    int count = 0;
    int KthData = 9999;
    while(1) {
        count++;
        if(count == k) {            // k��° �� �� �ӽ� ������ ������ ����Ű�� ����� ���� ��ȯ
            return pointer -> data;
        }
        pointer = pointer -> next;  // �ӽ� ������ ������ ���� ��带 ����Ŵ
    }
    return KthData;
}

void printReverse(Node* head) {     // ���Ḯ��Ʈ�� �Ųٷ� ����ϴ� ��� �Լ�
    if(head == NULL) {
        return;
    }
    printReverse(head -> next);
    printf("%d ", head -> data);
}

int main() {
    Node* head = NULL;              // head�� �޸� �Ҵ� �ʿ����. ���������� �Ű������� ����

    append(&head, 9);
    append(&head, 8);
    append(&head, 4);
    append(&head, 14);
    append(&head, 5);

    printReverse(head);

    printf("\n%dth last node is %d\n", 2, getKthNodeFromLast(head, 2));
}