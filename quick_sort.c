#include<stdio.h>

void printArray(int* A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

int partition(int* A, int low, int high) {
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do {
        while (i <= high && A[i] <= pivot) {
            i++;
        }
        while (j >= low && A[j] > pivot) {
            j--;
        }
        if (i < j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int* A, int low, int high) {
    int partitionIndex; // Index of pivot after partition

    if (low < high) {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1); // sort left array
        quickSort(A, partitionIndex + 1, high); // sort right array
    }
}

int main() {
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}