int majorityElement(int* nums, int numsSize) {
    return vote(nums, numsSize);
}

int vote(int *nums, int numsSize)
{
	int votes = 0;
	int candidate = 0;

	for (int i = 0; i < numsSize; ++i)
	{
		if (votes == 0)
		{
			candidate = nums[i];
			votes++;
		}
		else
		{
			if (candidate == nums[i])
				votes++;
			else
				votes--;
		}
	}
	return candidate;
}
