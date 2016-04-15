/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
  struct TreeNode *result;

	if (root == NULL || p == NULL || q == NULL)
		return NULL;

	if ((root->val >= p->val && root->val <= q->val) || (root->val >= q->val && root->val <= p->val))  
		return root;

	if (p == q)
		return p;

	if (root->val >= p->val && root->val >= q->val)
		result = lowestCommonAncestor(root->left, p, q);
	else
		result = lowestCommonAncestor(root->right, p, q);

	return result;
    
}
