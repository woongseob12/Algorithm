#include <stdio.h>

int main()
{
	int a,b;
	int i,j;
	scanf("%d",&j);
	for (i=1;i<=j;i++)
	{
		scanf("%d %d",&a,&b);
		printf("Case #%d: %d\n",i,a+b);
	}
	return 0;
}

