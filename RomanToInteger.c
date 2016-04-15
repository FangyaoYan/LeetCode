int romanToInt(char* s) {
  int slen = strlen(s);
	int *cvt;
	int integer = 0;

	cvt = (int *)malloc(sizeof(s) * slen);

	for (int i = 0; i < slen; ++i)
	{
		switch(s[i])
		{
			case 'I' : cvt[i] = 1; break;
			case 'V' : cvt[i] = 5; break;
			case 'X' : cvt[i] = 10; break;
			case 'L' : cvt[i] = 50; break;
			case 'C' : cvt[i] = 100; break;
			case 'D' : cvt[i] = 500; break;
			case 'M' : cvt[i] = 1000; break;
		}
	}
	for (int i = 0; i < slen; ++i)
	{
		if ((cvt[i] > cvt[i - 1]) && (i > 0))
			integer += cvt[i] - 2 * cvt[i - 1];
		else
			integer += cvt[i];
	}
	free(cvt);
	return integer;
}
