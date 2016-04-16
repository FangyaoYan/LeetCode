int maxProfit(int* prices, int pricesSize) {
	int maxProfit = 0, minPrice = prices[0], currentProfit;

	for (int i = 1; i < pricesSize; ++i)
	{
		if (prices[i] < minPrice)
			minPrice = prices[i];
		else
		{
		    currentProfit = prices[i] - minPrice;
    		maxProfit = maxProfit > currentProfit ? maxProfit : currentProfit;
		}
	}
	return maxProfit;
}
