#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *arr;
};

char stackTop(struct stack *sp) {
    if (sp->top == -1) {
        return '\0';  // Handle the case of an empty stack
    }
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, char val) {
    if (isFull(ptr)) {
        printf("Stack Overflow\n");
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow\n");
        return '\0';  // Return null character on underflow
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch) {
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else    
        return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

char* infixToPostfix(char *infix) {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));
    char *postfix = (char*)malloc((strlen(infix)+1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else {
            while (!isEmpty(sp) && precedence(infix[i]) <= precedence(stackTop(sp))) {
                postfix[j] = pop(sp);
                j++;
            }
            push(sp, infix[i]);
            i++;
        }
    }
    while (!isEmpty(sp)) {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    free(sp->arr);
    free(sp);
    return postfix;
}

int main() {
    char *infix = "a-b+c/6";
    char *postfix = infixToPostfix(infix);
    printf("Postfix: %s", postfix);

    free(postfix);
    return 0;
}