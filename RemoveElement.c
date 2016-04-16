int removeElement(int* nums, int numsSize, int val) {
    int realSize = numsSize;
    int i = 0, j = numsSize - 1;

    while (i <= j)
    {
    	while (nums[j] == val && j >= i)
    	{
    		--j;
    		--realSize;
    	}
    	if (j < i)
    	    break;
    	if (nums[i] == val)
    	{
    		nums[i++] = nums[j--];
    		--realSize;
    	}
    	else
    		++i;
    }
    return realSize;
}
