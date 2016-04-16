/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    
  struct ListNode* slavehead;
	struct ListNode* p;
	struct ListNode* q;

	if (head == NULL || head->next == NULL || head->next->next == NULL)
		return head;

	p = head->next;
	q = head;
	slavehead = p;

	while(p->next != NULL)
	{
		q->next = p->next;
		p->next = q->next->next;
		q = q->next;
		p = p->next;
		if (q == NULL || p == NULL)
			break;
	}

	q->next = slavehead;

	return head;
	return head;
	
}
