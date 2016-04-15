/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int left_depth, right_depth;
    if (root == NULL)
        return 0;
    else {
        left_depth = maxDepth(root->left);
        right_depth = maxDepth(root->right);
        return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
    }
}
