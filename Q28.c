/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, val;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &val);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } 
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make circular
    temp->next = head;

    // Traversal
    struct Node* current = head;

    if(head != NULL) {
        do {
            printf("%d ", current->data);
            current = current->next;
        } while(current != head);
    }

    return 0;
}