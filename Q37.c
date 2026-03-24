/*
Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/
#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

// ---------- Heapify Up ----------
void heapifyUp(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] <= heap[i]) break;

        int t = heap[p];
        heap[p] = heap[i];
        heap[i] = t;

        i = p;
    }
}

// ---------- Heapify Down ----------
void heapifyDown(int i) {
    while (1) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int smallest = i;

        if (l < size && heap[l] < heap[smallest])
            smallest = l;
        if (r < size && heap[r] < heap[smallest])
            smallest = r;

        if (smallest == i) break;

        int t = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = t;

        i = smallest;
    }
}

// ---------- Insert ----------
void insert(int x) {
    heap[size] = x;
    heapifyUp(size);
    size++;
}

// ---------- Delete ----------
int deleteMin() {
    if (size == 0) return -1;

    int val = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);

    return val;
}

// ---------- Peek ----------
int peek() {
    if (size == 0) return -1;
    return heap[0];
}

// ---------- Main ----------
int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } 
        else if (strcmp(op, "delete") == 0) {
            printf("%d\n", deleteMin());
        } 
        else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}