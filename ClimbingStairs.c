int climbStairs(int n) {
	int stair1, stair2, ways = 0;

	stair1 = 1;
	stair2 = 2;

	if (n <= 2)
		return n;
	while (n >= 3)
	{
		ways = stair1 + stair2;
		stair1 = stair2;
		stair2 = ways;
		--n;
	}
	return ways;
}
