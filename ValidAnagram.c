bool isAnagram(char* s, char* t) {
  int slen, tlen;
	int cnts[26] = {0};
	int cntt[26] = {0};

	slen = strlen(s);
	tlen = strlen(t);
	
	if (slen != tlen)
		return 0;
	for (int i = 0; i < slen; ++i)
	{
		cnts[s[i] - 'a']++;
		cntt[t[i] - 'a']++;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (cnts[i] != cntt[i])
		  return 0;
	}
	return 1;
}
