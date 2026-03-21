/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    int popped = temp->data;
    *top = temp->next;
    free(temp);
    return popped;
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;

    for (int i = 0; exp[i] != '\0'; i++) {

        // Skip spaces
        if (exp[i] == ' ')
            continue;

        // If digit, push to stack
        if (isdigit(exp[i])) {
            push(&stack, exp[i] - '0');
        }
        else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            int result;

            switch (exp[i]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}

// Main function
int main() {
    char exp[] = "2 3 1 * + 9 -";

    printf("Result = %d\n", evaluatePostfix(exp));

    return 0;
}