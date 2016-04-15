/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
  struct ListNode *p, *q;

	if (head == NULL || head->next == NULL)
		return head;
	p = head;
	while(p != NULL && p->next != NULL)
	{
		if (p->val == p->next->val)
		{
			q = p->next;
			p->next = p->next->next;
			free(q);
		}
		else
		    p = p->next;
	}

	return head;
	
}
