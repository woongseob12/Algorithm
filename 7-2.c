#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numOfNum;
	int sum,i;
	int score;
	scanf("%d",&numOfNum);
	char *p;
	p = (char *)malloc(sizeof(char)*numOfNum);
	scanf("%s",p);
	sum = 0;
	for(i = 0;i<numOfNum; i++){
		score = (int)p[i] - '0';
		sum += score;
	}
	printf("%d\n",sum);
	free(p);
	return 0;
}
