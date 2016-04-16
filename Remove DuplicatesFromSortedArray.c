int removeDuplicates(int* nums, int numsSize) {
    int i = 0, j = 1;
    int realSize = numsSize;
    while(j < numsSize)
    {
        if (nums[j] == nums[i])
        {
            ++j;
            --realSize;
        }
        else
            nums[++i] = nums[j++];
    }

    return realSize;
}
