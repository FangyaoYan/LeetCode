/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isBalanced(struct TreeNode* root) {
    
    if(root == NULL)
        return 1;
    if(abs(maxDepth(root->left) - maxDepth(root->right)) <= 1)
        return isBalanced(root->left) && isBalanced(root->right);
    else
        return 0;
}

int maxDepth(struct TreeNode* root) {
    
    int left_depth, right_depth;
    if(root == NULL)
        return 0;
    left_depth = maxDepth(root->left);
    right_depth = maxDepth(root->right);
    return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
}

