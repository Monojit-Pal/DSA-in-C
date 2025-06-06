#include<stdio.h>

int binarySearch(int arr[], int size, int element) {
    int low, mid, high;
    low = 0;
    high = size;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == element) {
            return mid;
        } else if (arr[mid] >= element) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 14, 15, 36, 44, 45, 49, 62, 70};
    int size = sizeof(arr) / sizeof(int);
    int element = 5;
    int searchIndex = binarySearch(arr, size, element);
    if (searchIndex != -1) {
        printf("The element %d found at index %d\n", element, searchIndex);
    } else {
        printf("Element not found");
    }
    return 0;
}
