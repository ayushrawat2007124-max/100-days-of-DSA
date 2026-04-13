/*Problem: BST Insert

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert into BST
struct Node* insert(struct Node* root, int val) {
    // If tree is empty
    if (root == NULL) {
        return createNode(val);
    }

    // Insert in left subtree
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    // Insert in right subtree
    else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Inorder traversal (to check BST)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;

    // Inserting values
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);

    // Print inorder traversal
    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}