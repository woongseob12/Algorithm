#include <stdio.h>

int main()
{
	int i,j;
	int cnt = 0;
	int num[10];
	for (i = 0; i<10;i++){
		scanf("%d",&num[i]);
	}
	for (i = 0; i<10;i++){
		num[i] %= 42;
	}
	for (i = 0; i<10;i++){
		for(j =i+1;j<10;j++){
			if((num[i] != 43)&&(num[i] == num[j])){
				num[j] = 43;
			}
		}
	}
	for (i = 0; i< 10; i++){
		if(num[i] != 43){
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}




