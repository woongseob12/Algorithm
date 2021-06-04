#include <stdio.h>

int main()
{
	int a,b;
	double res;
	scanf("%d %d",&a,&b);
	res = (double)a/(double)b;
	printf("%.9f\n", res);
	return 0;
}
