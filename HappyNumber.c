int split(int n)
{
	int p, q, result = 0;
	while (n >= 10)
	{
		q = n % 10;
		n = n / 10;
		result += q * q;
	}
	result += n * n;

	return result;
}

int isInMap(int map[], int temp, int size)
{
	int flag = 0;

	if (size == 0)
		return flag;

	for (int i = 0; i < size; ++i)
	{
		if (map[i] == temp)
		{
			flag = 1;
			break;
		}
	}

	return flag;
}

bool isHappy(int n) {
    
    int map[100] = {0}; // map keeps the numbers in the loop
	int *ptr = map;
	int temp = 0;
	int flag = 0;
	int result = 0;

	temp = split(n);

	while (temp != 1)
	{
		if (isInMap(map, temp, ptr - map))
		{
			result = 0;
			break;
		}
		else
		{
			*ptr++ = temp;
			temp = split(temp);
		}
	}

	if (temp == 1)
		result = 1;

	return result;
	
}
