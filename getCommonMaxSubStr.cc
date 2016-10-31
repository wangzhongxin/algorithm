char *getCommonMaxSubStr(char *ptr1, char *ptr2, int *getlen)
{
	int len = strlen(ptr1);
	int *parr = (int *)malloc(sizeof(int)*len);
	for (int i = 0; i < len; ++i)
	{
		int max = 0;	
		for (int j = 0; j < (int)strlen(ptr2); ++j)
		{
			int si = i;
			int sj = j;
			int num = 0;
			while (*(ptr1 + si) == *(ptr2 + sj) && *(ptr2+sj)!='\0')
			{
				++si;
				++sj;
				++num;
			}
			if (num > max)
				max = num;
		}
		parr[i] = max;
	}

	int sublen = 0;
	int *ptr = NULL;
	for (int i = 0; i < len; ++i)
	{
		if (parr[i]>sublen)
		{
			sublen = parr[i];
			ptr = &parr[i];
		}
	}
	*getlen = sublen;
	len = ptr - parr;
	free(parr);
	return ptr1 +len;
}