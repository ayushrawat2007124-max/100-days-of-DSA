/*Problem: Deque (Double-Ended Queue)

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
- Results of operations such as front, back, size, or the final state of the deque after all operations
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front, rear, size, cap;
} Deque;
Deque* createDeque(int cap) {
    Deque* dq = malloc(sizeof(Deque));
    dq->arr = malloc(sizeof(int) * cap);
    dq->front = 0;
    dq->rear = cap - 1;
    dq->size = 0;
    dq->cap = cap;
    return dq;
}
bool empty(Deque* dq) {
    return dq->size == 0;
}

int size(Deque* dq) {
    return dq->size;
}
void push_front(Deque* dq, int val) {
    if (dq->size == dq->cap) return;

    dq->front = (dq->front - 1 + dq->cap) % dq->cap;
    dq->arr[dq->front] = val;
    dq->size++;
}
void push_back(Deque* dq, int val) {
    if (dq->size == dq->cap) return;

    dq->rear = (dq->rear + 1) % dq->cap;
    dq->arr[dq->rear] = val;
    dq->size++;
}
int pop_front(Deque* dq) {
    if (empty(dq)) return -1;

    int val = dq->arr[dq->front];
    dq->front = (dq->front + 1) % dq->cap;
    dq->size--;
    return val;
}
int pop_back(Deque* dq) {
    if (empty(dq)) return -1;

    int val = dq->arr[dq->rear];
    dq->rear = (dq->rear - 1 + dq->cap) % dq->cap;
    dq->size--;
    return val;
}
int front(Deque* dq) {
    return empty(dq) ? -1 : dq->arr[dq->front];
}
int back(Deque* dq) {
    return empty(dq) ? -1 : dq->arr[dq->rear];
}
void clear(Deque* dq) {
    dq->front = 0;
    dq->rear = dq->cap - 1;
    dq->size = 0;
}
void reverse(Deque* dq) {
    int i = 0, j = dq->size - 1;
    while (i < j) {
        int a = (dq->front + i) % dq->cap;
        int b = (dq->front + j) % dq->cap;

        int t = dq->arr[a];
        dq->arr[a] = dq->arr[b];
        dq->arr[b] = t;

        i++; j--;
    }
}

void printDeque(Deque* dq) {
    for (int i = 0; i < dq->size; i++) {
        printf("%d ", dq->arr[(dq->front + i) % dq->cap]);
    }
    printf("\n");
}

void freeDeque(Deque* dq) {
    free(dq->arr);
    free(dq);
}