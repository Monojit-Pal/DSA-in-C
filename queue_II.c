#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void enqueue(struct Node **f, struct Node **r) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Queue is full\n");
    } else {
        int num;
        printf("Enter data: ");
        scanf("%d", &num);
        n->data = num;
        n->next = NULL;
        if (*f == NULL) {
            *f = n;
            *r = n;
        } else {
            (*r)->next = n;
            *r = n;
        }
    }
}

int dequeue(struct Node **f) {
    struct Node *n = *f;
    if (*f == NULL) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int val = n->data;
        *f = (*f)->next;
        free(n);
        return val;
    }
}

void display(struct Node *f) {
    while (f != NULL) {
        printf("%d\t", f->data);
        f = f->next;
    }
    printf("\n");
}

int main() {
    enqueue(&f,&r);
    enqueue(&f,&r);
    enqueue(&f,&r);
    enqueue(&f,&r);
    display(f);
    printf("Element removed: %d\n", dequeue(&f));
    display(f);
    return 0;
}