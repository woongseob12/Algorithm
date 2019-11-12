#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j,sum,score;
	char ox[80];
	int testCaseNum;
	scanf("%d",&testCaseNum);
	int *p;
	p = (int*)malloc(sizeof(int)*testCaseNum);

	for(i = 0 ; i < testCaseNum; i++){
		scanf("%s",ox);
		sum = 0;
		score = 0;
		for(j = 0; j < 80 ; j++){
			if (ox[j] =='\0'){
				break;}
			else if (ox[j] == 'O'){
				score++;
				sum += score;
			}
			else if (ox[j] == 'X'){
				score = 0;
			}
		}
		p[i] = sum;	
	}
	for(i = 0; i < testCaseNum; i++){
		printf("%d\n",p[i]);
	}
	free(p);
	return 0;
}

