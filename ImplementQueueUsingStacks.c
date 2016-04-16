typedef struct
{
	int arr[10000];
	int top;
} stack;

typedef struct {
	stack s1;
	stack s2;
	int maxSize;
} Queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
	queue->s1.top = -1;
	queue->s2.top = -1;
	queue->maxSize = maxSize;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
    if (queue->s1.top + queue->s2.top < queue->maxSize - 2)
    	queue->s1.arr[++queue->s1.top] = element;
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
    if (queue->s2.top == -1)
    {
    	while(queue->s1.top != 0)
    		queue->s2.arr[++queue->s2.top] = queue->s1.arr[queue->s1.top--];
    	queue->s1.top = -1;
    }
    else
    	--queue->s2.top;
}

/* Get the front element */
int queuePeek(Queue *queue) {
    if (queue->s2.top == -1)
    {
    	while(queue->s1.top != -1)
    		queue->s2.arr[++queue->s2.top] = queue->s1.arr[queue->s1.top--];
    	return queue->s2.arr[queue->s2.top];
    }
    else
    	return queue->s2.arr[queue->s2.top];
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
    if (queue->s1.top == -1 && queue->s2.top == -1)
    	return true;
    else
    	return false;
}
void queueDestroy(Queue *queue) {
    queue->s1.top = queue->s2.top = -1;
}
