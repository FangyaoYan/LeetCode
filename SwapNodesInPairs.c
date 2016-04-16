/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    
	struct ListNode *p, *q, *r = NULL;

	if (head == NULL || head->next == NULL)
		return head;
	p = head;
	q = p->next;
	head = head->next;
	while (q != NULL)
	{
		if (r != NULL)
			r->next = q;
		r = p;
		p->next = q->next;
		q->next = p;
		if ((p = p->next) == NULL)
			break;
		else
			q = p->next;
	}

	return head;
	
}
