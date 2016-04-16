int rob(int* nums, int numsSize) {
  int *max;
	int size = numsSize + 2;
	int prev, current;

	max = (int *)malloc(sizeof(int) * size);
	memset(max, 0, sizeof(int) * size);
	for (int i = 2; i < size; ++i)
	{
		prev = *(max + i - 1);
		current = *(max + i - 2) + nums[i - 2];
		*(max + i) =prev > current ? prev : current;
	}
	return *(max + size - 1);
}
