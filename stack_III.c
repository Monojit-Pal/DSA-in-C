#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top) {
    if (top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(struct Node *top) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL) {
        return 1;
    } else {
        return 0;
    }
}

struct Node * push(struct Node *top, int x) {
    if(isFull(top)) {
        printf("Stack Overflow\n");
    } else {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
    }
    return top;
}

struct Node * pop(struct Node *top) {
    if (isEmpty(top)) {
        printf("Stack Underflow\n");
    } else {
        struct Node *n = top;
        top = top->next;
        int x = n->data;
        printf("Element poped: %d\n", x);
        free(n);
    }
    return top;
}

int peak(struct Node *top, int pos) {
    struct Node *ptr = top;
    for (int i = 0; i < pos - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }
    if (ptr != NULL) {
        return ptr->data;
    } else {
        return -1;
    }
}

int main() {
    struct Node *top = NULL;
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    int elem = peak(top, 2);
    printf("Element at position 1: %d\n", elem);
    top = pop(top);
    linkedlisttraversal(top);
    return 0;
}
