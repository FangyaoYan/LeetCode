/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    
  int k = -1;
	int *result;
	int i, j;

	for (i = 0; i < numsSize - 1; ++i)
	{
		for (j = i + 1; j < numsSize; ++j)
		{
			if (nums[i] + nums[j] == target)
			{
				k = j;
				break;
			}
		}

		if (k != -1)
			break;
	}

	result = (int *)malloc(sizeof(int) * 2);
	result[0] = i;
	result[1] = k;

	return result;
	
}
