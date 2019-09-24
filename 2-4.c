#include <stdio.h>

int main()
{
	int H,M;
	scanf("%d %d",&H,&M);
	M = M-45;
	if (M<0)
	{
		H = H-1;
		M = 60 + M;
	}
	printf("%d %d\n",H,M);
	return 0;
}

