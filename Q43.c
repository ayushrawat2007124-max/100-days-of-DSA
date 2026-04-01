/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/
#include <stdio.h>

#define MAX 100

int main() {
    int n, i;
    scanf("%d", &n);

    int queue[MAX], stack[MAX];
    int front = 0, rear = -1, top = -1;

    // Input: enqueue
    for(i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        queue[++rear] = x;
    }

    // Step 1: Queue -> Stack
    while(front <= rear) {
        stack[++top] = queue[front++];
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Step 2: Stack -> Queue
    while(top >= 0) {
        queue[++rear] = stack[top--];
    }

    // Output reversed queue
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}