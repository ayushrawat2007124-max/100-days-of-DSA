/*
Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &m);

    int front = 0;
    int rear = n - 1;
    int size = n;

    // Perform m dequeues
    for (int i = 0; i < m; i++) {
        if (size > 0) {
            front = (front + 1) % n;
            size--;
        }
    }

    // Print remaining elements
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[(front + i) % n]);
    }

    free(arr);
    return 0;
}