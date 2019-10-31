#include <stdio.h>
#include <stdlib.h>
int main()
{
	int testCase,aryNum;
	int i,cnt,studentNum;
	int sum,score,avg;
	int *aP;
	double *p;
	scanf("%d",&testCase);
	aryNum = testCase;
	p = (double*)malloc(sizeof(double)*testCase);
	while(testCase>0)
	{
		scanf("%d",&studentNum);
		sum = 0;
		cnt = 0;
		aP = (int*)malloc(sizeof(int)*studentNum);
		for(i = 0;i<studentNum;i++){
			scanf("%d",&aP[i]);
			sum +=aP[i];
		}
		avg = sum/studentNum;
		for(i=0;i<studentNum;i++){
			if (aP[i] > avg){
				cnt++;
			}
		}
		p[aryNum-testCase] =(double)cnt/(double)studentNum;
		testCase--;
	}
	free(aP);
	for (i = 0;i < aryNum;i++){
		printf("%.3lf%%\n",p[i]*100);
	}
	free(p);
	return 0;
}












