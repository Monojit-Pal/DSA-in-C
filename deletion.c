#include<stdio.h>

void display(int arr[], int n) {
    // Traversal
    for (int i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int indDeletion(int arr[], int size, int index) {
    // code for Insertion
    if (size <= 0) {
        return -1;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return 1;
}

int main() {
    int arr[100] = {1, 2, 6, 78};
    int size = 4, index = 1;
    display(arr, size);
    indDeletion(arr, size, index);
    size -= 1;
    display(arr, size);
    return 0;
}