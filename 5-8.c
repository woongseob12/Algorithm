#include <stdio.h>
#include <stdlib.h>

int main()
{
	int caseNum, avg, sum = 0;
	int i,cnt=0;
	int *p;
	double per;

	scanf("%d",&caseNum);
	p=(int*)malloc(sizeof(int)*caseNum);
	for(i = 0; i< caseNum; i++)
	{
		scanf("%d",&p[i]);
	}
	for(i = 0; i < caseNum; i++)
	{
		sum+=p[i];
	}
	avg = sum/caseNum;
	for(i = 0; i < caseNum; i++)
	{
		if(avg < p[i]){
			cnt++;
		}
	}
	per = (double)cnt/(double)caseNum;
	printf("%.3f%%\n",per*100);
	free(p);
	return 0;
}






