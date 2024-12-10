#include<stdio.h>
#include<stdlib.h>

struct Node {
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

struct Node * deleteAtFirst(struct Node *head) {
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node * deleteAtIndex(struct Node *head, int index) {
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++) {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node * deleteAtLast(struct Node *head) {
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node * deleteByValue(struct Node *head, int value) {
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    if (q->data == value) {
        p->next = q->next;
        free(q);
    }
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
    // Terminate the list at the third node
    third->data = 21;
    third->next = NULL;

    printf("LinkedList before deletion:\n");
    linkedlisttraversal(head);

    printf("LinkedList after deletion:\n");
    //head = deleteAtFirst(head);
    //head = deleteAtIndex(head, 1);
    //head = deleteAtLast(head);
    head = deleteByValue(head, 15);

    linkedlisttraversal(head);

    return 0;
}
