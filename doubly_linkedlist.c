#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void traversalfromstart(struct Node *ptr) {
    do {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    } while (ptr->next != NULL);
    printf("\n");
}

void traversalfromend(struct Node *ptr) {
    do {
        printf("%d  ", ptr->data);
        ptr = ptr->prev;
    } while (ptr->prev != NULL);
    printf("\n");
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 16;
    head->prev = NULL;
    head->next = second;
    // Link second and third nodes
    second->data = 25;
    second->prev = head;
    second->next = third;
    // Link third and fourth
    third->data = 36;
    third->prev = second;
    third->next = fourth;

    fourth->data = 49;
    fourth->prev = third;
    fourth->next = fifth;

    fifth->data = 64;
    fifth->prev = fourth;
    fifth->next = NULL;

    traversalfromstart(head);
    traversalfromend(fifth);

    return 0;
}
