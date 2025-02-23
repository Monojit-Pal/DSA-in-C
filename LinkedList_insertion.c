#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node * insertAtFirst(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node * insertAtIndex(struct Node *head, int data, int index) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
    
}

struct Node * insertAtEnd(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    
    // Link first and second nodes
    head->data = 7;
    head->next = second;
    // Link second and third nodes
    second->data = 15;
    second->next = third;
    // Terminate the third node
    third->data = 21;
    third->next = NULL;

    printf("LinkedList before insertion:\n");
    linkedlisttraversal(head);

    printf("LinkedList after insertion:\n");
    //head = insertAtFirst(head, 65);
    //head = insertAtIndex(head, 56, 1);
    //head = insertAtEnd(head, 56);
    head = insertAfterNode(head, second, 45);

    linkedlisttraversal(head);

    return 0;
}
