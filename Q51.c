/*Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
struct TreeNode* searchBST(struct TreeNode* root, int key) {
    // Base case: not found or found
    if (root == NULL || root->val == key) {
        return root;
    }

    // Search in left subtree
    if (key < root->val) {
        return searchBST(root->left, key);
    }

    // Search in right subtree
    return searchBST(root->right, key);
}