// ���Ḯ��Ʈ ����: �ڿ��� k��° ��带 ����ϵ��� 
// append, getKthNodeFromLast, printList �Լ� �ۼ�

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void append(Node** head, int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = data;     // ���ο� ��忡 ������ ����
    new_node -> next = *head;    // ���ο� ��尡 head�� ����Ű�� ���� ����Ŵ
    *head = new_node;            // head�� ���ο� ��带 ����Ŵ
    printf("%2d is appended\n", data);
    return;
}

int get_kth_node_from_last (Node* head, int k) {
    Node* pointer = head;           // �ӽ� ������ ������ head�� ����Ű�� ���� ����Ŵ
    int count = 0;
    int kth_data = 9999;
    while(1) {
        count++;
        if(count == k) {            // k��° �� �� �ӽ� ������ ������ ����Ű�� ����� ���� ��ȯ
            return pointer -> data;
        }
        pointer = pointer -> next;  // �ӽ� ������ ������ ���� ��带 ����Ŵ
    }
    return kth_data;
}

void print_reverse(Node* head) {     // ���Ḯ��Ʈ�� �Ųٷ� ����ϴ� ��� �Լ�
    if(head == NULL) {
        printf("|");
        return;
    }
    print_reverse(head -> next);
    printf(" %d |", head -> data);
}

int main() {
    Node* head = NULL;              // head�� �޸� �Ҵ� �ʿ����. ���������� �Ű������� ����

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