#include <stdio.h>

int main()
{
	int num[1000000];
	int min = 1000001;
	int max = -1000001;
	int size;
	int i;
	scanf("%d",&size);
	for (i = 0;i<size;i++){
		scanf("%d",&num[i]);
		if(num[i]<min){
			min = num[i];
		}
		if(num[i]>max){
			max = num[i];
		}
	}
	printf("%d %d\n",min,max);
	return 0;
}

	

	
