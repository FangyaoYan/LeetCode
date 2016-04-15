void moveZeroes(int* nums, int numsSize) {
    // 效率不高的算法,多余计算量很多
    /*
    int i = 0, j;
    
    while(nums[i] != 0 && i < numsSize)
        i++;
    if(i < numsSize - 1)
    {
        j = i + 1;
        while(nums[j] == 0 && j < numsSize)
            j++;
        if(j != numsSize)
        {
            nums[i] = nums[j];
            nums[j] = 0;
            i++;
            moveZeroes(nums+i, numsSize-i);
        }
    }
    */
    
    // 效率较高的算法
    int i = 0, j = 0;
    
    while(j < numsSize)
    {
        if(nums[j] != 0)
        {
            nums[i] = nums[j]; //不需要在这里就将nums[i+1]赋为0,这个操作是多余的,因为现在赋为0之后,在后面的过程中有可能会被非零值覆盖掉,造成多余操作!!!
            i++;
        }
        j++;
    }
    while(i < numsSize)
    {
        nums[i] = 0;
        i++;
    }
    
    /* 下面的代码参考于网站:http://www.jianshu.com/p/f82a3dda76b8
    int index = 0; 
    
    for(int i = 0;i<numsSize;i++)
    { 
      if(nums[i] !=0)
      { 
        nums[index++] = nums[i];
      }
    }
    for(int i = index;i<numsSize;i++) {
        nums[i] = 0; 
    }
    */
}
