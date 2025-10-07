//Write a program to pass the pointer and array to the function for performing the
//multiplication of the numbers



#include <stdio.h>
int multiplyArray(int *arr, int n) {
    int product = 1;
    for (int i = 0; i < n; i++) {
        product *= *(arr + i);
    }
    return product;
}
int main() {
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = multiplyArray(arr, n);
    printf("Multiplication of all elements = %d\n", result);
    return 0;
}
