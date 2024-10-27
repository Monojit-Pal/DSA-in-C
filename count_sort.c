#include<stdio.h>

void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void count_sort(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    int count[max + 1];
    for(int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int j = 0;
    for(int i = 0; i <= max; i++) {
        while(count[i] > 0) {
            arr[j] = i;
            j++;
            count[i]--;
        }
    }
}

int main() {
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    print_array(A, n);
    count_sort(A, n);
    print_array(A, n);
    return 0;
}