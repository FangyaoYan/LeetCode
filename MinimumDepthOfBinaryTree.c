/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    int left_depth, right_depth;
    
    if(root == NULL)
        return 0;
    if ((root->left != NULL) && (root->right != NULL)) 
    {
        left_depth = minDepth(root->left);
        right_depth = minDepth(root->right);
        return left_depth < right_depth ? left_depth + 1 : right_depth + 1;
    }
    else if ((root->left != NULL) && (root->right == NULL))
        return minDepth(root->left) + 1;
    else if ((root->right != NULL) && (root->left == NULL))
        return minDepth(root->right) + 1;
    else
        return 1;
}
