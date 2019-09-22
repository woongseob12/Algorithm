#include <stdio.h>

int main()
{
	int a,b;
	int first,second,third,forth;
	scanf("%d %d",&a,&b);
	first = a*(b%10);
	second = a*((b%100)-(b%10));
	third = a*(b-(b%100));
	forth = first + second + third;
	printf("%d\n",first);
	printf("%d\n",second/10);
	printf("%d\n",third/100);
	printf("%d\n",forth);
	return 0;
}
