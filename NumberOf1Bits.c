int hammingWeight(uint32_t n) {
  unsigned int mask = 1;
	int cnt = 0;
	
	while(mask != 0)
	{
		if((mask & n) != 0)
			cnt++;
		mask <<= 1;
	}
	return cnt;
}
