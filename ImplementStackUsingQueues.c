typedef struct 
{
	int arr[1000];
	int front;
	int tail;
	int size;	
} Queue;

typedef struct {
    Queue q1;
    Queue q2;
    int maxSize;
} Stack;

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
    stack->maxSize = maxSize;
    stack->q1.front = stack->q1.tail = 0;
    stack->q2.front = stack->q2.tail = 0;
    stack->q1.size = stack->q2.size = 0;
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
    if (stack->q1.size + stack->q2.size < stack->maxSize)
    {
    	if (!stack->q2.size)
    	{
	    	stack->q1.arr[stack->q1.tail] = element;
	    	stack->q1.tail = (stack->q1.tail + 1) % stack->maxSize;
	    	++stack->q1.size;
    	}
    	else
    	{
    		stack->q2.arr[stack->q2.tail] = element;
    		stack->q2.tail = (stack->q2.tail + 1) % stack->maxSize;
	    	++stack->q2.size;
    	}
    }
}

/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
	if (stack->q1.size || stack->q2.size)
	{
	    if (!stack->q1.size)
	    {
	    	while(stack->q2.size != 1)
	    	{
	    		stack->q1.arr[stack->q1.tail] = stack->q2.arr[stack->q2.front];
	    		stack->q1.tail = (stack->q1.tail + 1) % stack->maxSize;
	    		stack->q2.front = (stack->q2.front + 1) % stack->maxSize;
	    		++stack->q1.size;
	    		--stack->q2.size;
	    	}
	    	stack->q2.front = (stack->q2.front + 1) % stack->maxSize;
	    	stack->q2.size = 0;
	    }
	    else
	    {
	    	while(stack->q1.size != 1)
	    	{
	    		stack->q2.arr[stack->q2.tail] = stack->q1.arr[stack->q1.front];
	    		stack->q2.tail = (stack->q2.tail + 1) % stack->maxSize;
	    		stack->q1.front = (stack->q1.front + 1) % stack->maxSize;
	    		++stack->q2.size;
	    		--stack->q1.size;
	    	}
	    	stack->q1.front = (stack->q1.front + 1) % stack->maxSize;
	    	stack->q1.size = 0;
	    }
	}
}

/* Get the top element */
int stackTop(Stack *stack) {
	int top;

    if (!stack->q1.size)
    {
    	while(stack->q2.size != 0)
    	{
    		if (stack->q2.size == 1)
    			top = stack->q2.arr[stack->q2.front];
    		stack->q1.arr[stack->q1.tail] = stack->q2.arr[stack->q2.front];
    		stack->q1.tail = (stack->q1.tail + 1) % stack->maxSize;
    		stack->q2.front = (stack->q2.front + 1) % stack->maxSize;
    		++stack->q1.size;
    		--stack->q2.size;
    	}
    }
    else
    {
    	while(stack->q1.size != 0)
    	{
    		if (stack->q1.size == 1)
    			top = stack->q1.arr[stack->q1.front];
    		stack->q2.arr[stack->q2.tail] = stack->q1.arr[stack->q1.front];
    		stack->q2.tail = (stack->q2.tail + 1) % stack->maxSize;
    		stack->q1.front = (stack->q1.front + 1) % stack->maxSize;
    		++stack->q2.size;
    		--stack->q1.size;
    	}
    }
    return top;
}

/* Return whether the stack is empty */
bool stackEmpty(Stack *stack) {
    if (stack->q1.size == 0 && stack->q2.size == 0)
    	return true;
    else
    	return false;
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
    stack->q1.size = stack->q2.size = 0;
    stack->q1.front = stack->q1.tail = 0;
    stack->q2.front = stack->q2.tail = 0;
    stack->maxSize = 0;
}
