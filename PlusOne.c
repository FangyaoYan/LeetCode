/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int c = 1, resultDigit;
	int *returnDigits;
	
    for (int i = digitsSize - 1; i > -1; --i)
    {
        resultDigit = (*(digits + i) + c) % 10;
    	c = (*(digits + i) + c) / 10;
    	*(digits + i) = resultDigit;
    }
    if (c == 1)
    {
    	returnDigits = (int *)malloc(sizeof(int) * (digitsSize + 1));
    	*returnDigits = 1;
    	memcpy(returnDigits + 1, digits, sizeof(int) * digitsSize);
    	*returnSize = digitsSize + 1;
    }
    else
    {
    	returnDigits = (int *)malloc(sizeof(int) * digitsSize);
    	memcpy(returnDigits, digits, sizeof(int) * digitsSize);
    	*returnSize = digitsSize;
    }
    return returnDigits;

}
