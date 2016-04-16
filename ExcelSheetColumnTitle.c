char* convertToTitle(int n) {
    
    static char buff[10];
	static char *buffptr;
	int r, size;
	char temp;

	if (n <= 0)
		return "";

	buffptr = buff;

	while (n > 0)
	{
		r = n % 26;
		n = n / 26;

		if (r != 0)
			*buffptr++ = 'A' + r - 1;
		else
		{
			*buffptr++ = 'Z';
			--n;
		}
	}

	*buffptr++ = 0;

	size = (buffptr - 1) - buff;

	for (int i = 0; i < size / 2; ++i)
	{
		temp = buff[i];
		buff[i] = buff[size - 1 - i];
		buff[size - 1 - i] = temp;
	}

	return buff;
    
}
