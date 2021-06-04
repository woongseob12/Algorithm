#include <stdio.h>

int main()
{
	int many,i;
	double num[1000];
	double max=0;
	double score = 0;
	scanf("%d",&many);
	for (i = 0;i<many;i++){
		scanf("%lf",&num[i]);
	}
	for (i = 0;i<many;i++){
		if(max<num[i]){
			max = num[i];
		}
	}
	for (i=0;i<many;i++){
		num[i] = num[i]/max*100.000;
	}
	for (i = 0; i<many;i++){
		score += num[i];
	}
	score = score/(double)many;
	printf("%.2lf\n",score);
	return 0;
}


