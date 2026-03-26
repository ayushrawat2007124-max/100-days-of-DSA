/*
Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

// Deque structure
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Deque;

// Create Deque
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

// Push Front
void push_front(Deque* dq, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = value;
    node->prev = NULL;
    node->next = dq->front;

    if (dq->front != NULL)
        dq->front->prev = node;
    else
        dq->rear = node;

    dq->front = node;
    dq->size++;
}

// Push Back
void push_back(Deque* dq, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = value;
    node->next = NULL;
    node->prev = dq->rear;

    if (dq->rear != NULL)
        dq->rear->next = node;
    else
        dq->front = node;

    dq->rear = node;
    dq->size++;
}

// Pop Front
int pop_front(Deque* dq) {
    if (dq->front == NULL) return -1;

    Node* temp = dq->front;
    int val = temp->val;

    dq->front = dq->front->next;
    if (dq->front != NULL)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(temp);
    dq->size--;
    return val;
}

// Pop Back
int pop_back(Deque* dq) {
    if (dq->rear == NULL) return -1;

    Node* temp = dq->rear;
    int val = temp->val;

    dq->rear = dq->rear->prev;
    if (dq->rear != NULL)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(temp);
    dq->size--;
    return val;
}

// Get Front
int front(Deque* dq) {
    if (dq->front == NULL) return -1;
    return dq->front->val;
}

// Get Back
int back(Deque* dq) {
    if (dq->rear == NULL) return -1;
    return dq->rear->val;
}

// Check Empty
bool empty(Deque* dq) {
    return dq->size == 0;
}

// Get Size
int size(Deque* dq) {
    return dq->size;
}

// Clear Deque
void clear(Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

// Reverse Deque
void reverse(Deque* dq) {
    Node* curr = dq->front;
    Node* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL) {
        dq->rear = dq->front;
        dq->front = temp->prev;
    }
}

// Print Deque
void printDeque(Deque* dq) {
    Node* temp = dq->front;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// Driver Code
int main() {
    Deque* dq = createDeque();

    push_back(dq, 10);
    push_front(dq, 5);
    push_back(dq, 20);

    printDeque(dq); // 5 10 20

    printf("Front: %d\n", front(dq));
    printf("Back: %d\n", back(dq));

    pop_front(dq);
    pop_back(dq);

    printDeque(dq); // 10

    printf("Size: %d\n", size(dq));

    clear(dq);
    printf("Empty: %d\n", empty(dq));

    return 0;
}