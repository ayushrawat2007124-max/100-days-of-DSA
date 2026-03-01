/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/
#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    k = k % n;  // handle k > n

    int rotated[n];

    // Copy last k elements to the front
    for(int i = 0; i < k; i++) {
        rotated[i] = arr[n - k + i];
    }

    // Copy first n-k elements after that
    for(int i = 0; i < n - k; i++) {
        rotated[k + i] = arr[i];
    }

    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", rotated[i]);
    }

    return 0;
}