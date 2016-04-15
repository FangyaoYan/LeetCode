int titleToNumber(char* s) {
  int slen;
	int sequence = 0;
	
	slen = strlen(s);

	if (slen == 0)
		return 0;
	for (int i = 0; i < slen; ++i)
		sequence = (int)pow(26, (slen - i - 1)) * (s[i] - 'A' + 1) + sequence;
	return sequence;
}
