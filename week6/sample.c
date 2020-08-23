#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} ListNode;

void listInit(ListNode* linkedList) {
    linkedList->next = NULL;
}

void append(ListNode* linkedList, int inputData) {
    printf("APPEND START\n");
    // ??¢§??? node¢¬? ¢¬¢¬??¡Æ? ¡Æ????? inputData ©©???
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode -> data = inputData;
    newNode -> next = NULL;

    ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
    temp = linkedList; // ??¢©? ©©??? ???? ?? ??¢§??? ¢¬?¢©????? ?????¡Æ ©©???¢¬? ¡Æ?¢¬??¡Æ¡Æ? ??.
    while(temp->next != NULL) {    // ??¢§??? ¢¬?¢©????? ?????¡Æ ©©????? next¡Æ? ????¡Æ??? ¡Æ?¢¬??¡Æ¡Æ? ???? ???? ?¡×???? (¢¬???¢¬¢§ ©©????? ?¡×????)
        printf("in while\n");
        temp = temp -> next; // ¢¥??¢© ©©???¢¬? ¡Æ?¢¬????¡© ¢¬???¢¬¢§ ©©???¢§? ????
    }
    temp -> next = newNode; // ¢¬???¢¬¢§ ©©????? next¡Æ? newNode(??¢§??? ©©???)¢¬? ¡Æ?¢¬??¡Æ¡Æ? ??.
    printf("APPEND DONE\n");
    // free()¢¥? ?©¢???????
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *newList = (ListNode*)malloc(sizeof(ListNode));
    ListNode *tempPointer = newList;

    list1 = list1 -> next;
    list2 = list2 -> next;

    while(list1 != NULL && list2 != NULL) {
        if(list1 -> data <= list2 -> data) {
            tempPointer -> next = list1;
            list1 = list1 -> next;
        } else {
            tempPointer -> next = list2;
            list2 = list2 -> next;
        }
        tempPointer = tempPointer -> next;
    }
    if(list1 != NULL) {
        printf("1ST list END\n");
        tempPointer -> next = list1;
    }
    if(list2 != NULL) {
        printf("2ND list END\n");
        tempPointer -> next = list2;
    }
    return newList;
}

void printList(ListNode* linkedList) {
    printf("| ");
    while(linkedList -> next != NULL) {
        printf("%d | ", linkedList -> next -> data); // ?¡À???????? linkedList¡Æ? ?©©?¢© ¡Æ?¢¬??¡Æ¢¥? ©©??? ?????? data¢¥? ??¢¥?! next¡Æ? ¡Æ?¢¬??¡Æ¢¥? data¡Æ? ????¢´? ©©????? ¡Æ???¢¥?.
        linkedList = linkedList -> next;
    }
    printf("\n");
}


int main() {
    // ??¡Æ?¢¬?¢©??? ?? ¡Æ©© ???©¢
    ListNode* listA = (ListNode*)malloc(sizeof(ListNode));
    ListNode* listB = (ListNode*)malloc(sizeof(ListNode));

    // ??¡Æ?¢¬?¢©??? ?????¡©
    listInit(listA);
    listInit(listB);

    // ??¡Æ?¢¬?¢©????? ???? ©©???
    append(listA, 2);
    append(listA, 6);
    append(listA, 9);
    append(listA, 10);
    printList(listA);
    
    append(listB, 1);
    append(listB, 5);
    append(listB, 7);
    append(listB, 8);
    append(listB, 11);
    printList(listB);

    ListNode* mergedLinkedList = mergeTwoLists(listA, listB);
    printList(mergedLinkedList);
    printf("main end");
}