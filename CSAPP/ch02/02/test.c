#include<stdio.h>
void inplace_swap(int *x, int *y) {
    if (x == y) return;
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}
void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt-1; first <= last; first++,last--)
    inplace_swap(&a[first], &a[last]);
}

int main() {
    int size = 5;
    int arr[] = {1, 2, 3, 4, 5};
    reverse_array(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}