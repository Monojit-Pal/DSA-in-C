#include<stdio.h>

void printArray(int* A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (A[min] > A[j]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = A[min];
            A[min] = A[i];
            A[i] = temp;
        }
    }
}

int main() {
    int A[] = {12, 54, 65, 7, 23, 9};
    //int A[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);
    return 0;
}