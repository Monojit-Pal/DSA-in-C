#include<stdio.h>
#include<stdlib.h>

struct circularQueue {
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularQueue *q) {
    return (q->f == q->r);
}

int isFull(struct circularQueue *q) {
    return ((q->r+1)%q->size == q->f);
}

void enqueue(struct circularQueue *q, int val) {
    if (isFull(q)) {
        printf("Circular Queue is full");
    } else {
        q->r = (q->r+1) % q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct circularQueue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("Circular Queue is full");
    } else {
        q->f = (q->f+1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int display(struct circularQueue *q) {
    for (int i = q->f+1; i <= q->r; i++) {
        printf("%d\t", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct circularQueue q;
    q.size = 5;
    q.f = 0;
    q.r = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 17);
    enqueue(&q, 19);
    enqueue(&q, 11);
    display(&q);
    printf("Removed element: %d\n", dequeue(&q));
    display(&q);

    return 0;
}