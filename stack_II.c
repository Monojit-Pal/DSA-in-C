#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr) {
    if (ptr->top == -1) {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr) {
    if (ptr->top == ptr->size - 1) {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int val) {
    if (isFull(ptr)) {
        printf("Stack Overflow");
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow");
        return -1;
    } else {
        int val = ptr->arr[ptr->top];
        ptr->top--;
    }
}

int main() {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int*)malloc(sp->size*(sizeof(int)));
    printf("Stack has been created successfully\n");

    printf("%d\n", isEmpty(sp));
    printf("%d\n", isFull(sp));

    return 0;
}