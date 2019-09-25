#include <stdio.h>

int main()
{
	int num[1000000];
	int size;
	int i,j,temp;
	scanf("%d",&size);
	for (i = 0;i<size;i++){
		scanf("%d",&num[i]);
	}
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++)
		{
			if(num[i]>num[j]){
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	printf("%d %d\n",num[0],num[size-1]);
	return 0;
}

	

	
