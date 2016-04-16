bool isPowerOfTwo(int n) {
  int times = 0;
	int flag = 0;
	
	if (n <= 0)
		return 0;
	while( times < 32 )
	{
		if ((1 << times++) == n)
		{
			flag = 1;
			break;
		}
	}
	return flag;
	//return n > 0 && !(n & n - 1);
}
