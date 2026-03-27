/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int arr[MAX];
    int size;
} MinHeap;

// Swap
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify Up
void heapifyUp(MinHeap* h, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->arr[parent] > h->arr[i]) {
            swap(&h->arr[parent], &h->arr[i]);
            i = parent;
        } else break;
    }
}

// Heapify Down
void heapifyDown(MinHeap* h, int i) {
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < h->size && h->arr[left] < h->arr[smallest])
            smallest = left;

        if (right < h->size && h->arr[right] < h->arr[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&h->arr[i], &h->arr[smallest]);
            i = smallest;
        } else break;
    }
}

// Insert
void insert(MinHeap* h, int val) {
    h->arr[h->size] = val;
    heapifyUp(h, h->size);
    h->size++;
}

// Extract Min
int extractMin(MinHeap* h) {
    if (h->size == 0) return -1;

    int min = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    heapifyDown(h, 0);
    return min;
}

// Peek
int peek(MinHeap* h) {
    if (h->size == 0) return -1;
    return h->arr[0];
}

// Driver
int main() {
    int N;
    scanf("%d", &N);

    MinHeap h;
    h.size = 0;

    while (N--) {
        char op[20];
        scanf("%s", op);

        if (op[0] == 'i') { // insert
            int x;
            scanf("%d", &x);
            insert(&h, x);
        }
        else if (op[0] == 'e') { // extractMin
            printf("%d\n", extractMin(&h));
        }
        else if (op[0] == 'p') { // peek
            printf("%d\n", peek(&h));
        }
    }

    return 0;
}