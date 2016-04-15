/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *temp;
    
    if(node == NULL && node->next == NULL)
        return;
    temp = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    free(temp);
}
