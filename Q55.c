/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue node (for BFS with HD)
struct QNode {
    struct Node* node;
    int hd;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    free(queue);
    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    // Queue for BFS
    struct QNode* queue = (struct QNode*)malloc(1000 * sizeof(struct QNode));
    int front = 0, rear = 0;

    // Store result using array of arrays
    int map[200][100];   // HD range [-100,100]
    int count[200] = {0};

    // Offset for negative HD
    int offset = 100;

    queue[rear++] = (struct QNode){root, 0};

    int min_hd = 0, max_hd = 0;

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        int idx = hd + offset;

        map[idx][count[idx]++] = curr->data;

        if (hd < min_hd) min_hd = hd;
        if (hd > max_hd) max_hd = hd;

        if (curr->left)
            queue[rear++] = (struct QNode){curr->left, hd - 1};

        if (curr->right)
            queue[rear++] = (struct QNode){curr->right, hd + 1};
    }

    // Print vertical order
    for (int i = min_hd; i <= max_hd; i++) {
        int idx = i + offset;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }

    free(queue);
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}