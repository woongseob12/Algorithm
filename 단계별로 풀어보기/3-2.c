#include <stdio.h>

int main()
{
	int range;
	int i;
	int a,b;
	scanf("%d",&range);
	for (i = 0; i<range;i++)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",a+b);
	}
	return 0;
}
