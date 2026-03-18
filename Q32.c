/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/


#include <stdio.h>

int main() {
    int n, m;

    // Input number of elements
    scanf("%d", &n);

    int stack[100];  // assuming max size 100

    // Push elements into stack
    for (int i = 0; i < n; i++) {
        scanf("%d", &stack[i]);
    }

    // Input number of pops
    scanf("%d", &m);

    int top = n - 1;

    // Pop operation
    for (int i = 0; i < m; i++) {
        if (top >= 0) {
            top--;   // remove top element
        }
    }

    // Print remaining elements (top to bottom)
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}