#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row,i,j,sum,score;
	char **ox;
	int *result;
	scanf("%d",&row);
	ox=(char**)malloc(sizeof(char)*row);
	result=(int*)malloc(sizeof(int)*row);
	for(i = 0; i<row;i++){
		ox[i] = (char*)malloc(sizeof(char*)*80);
	}
	for(i = 0; i < row ; i++){
		scanf("%s",ox[i]);
	}
	for (i = 0; i< row; i++){
		sum = 0;
		score = 1;
		for (j = 0; j<80;j++){
			 if(ox[i][j] == 'O'){
				  sum += score;
				  score ++;
				  }
			 else if(ox[i][j] == 'X'){
				 score = 1;
			 }
			 else{
				 ;
			 }
		}
		result[i] = sum;
	}
	for (i = 0; i <row;i++){
		printf("%d\n",result[i]);
	}
	free(result);
	for(i = 0;i<row;i++){
		free(ox[i]);
	}
	return 0;
}

