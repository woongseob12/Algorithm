#include <stdio.h>

int main()
{
	int num[9];
	int max = 0;
	int i,cnt;
	for(i = 0; i<9;i++){
		scanf("%d",&num[i]);
		if(max<num[i]){
			max = num[i];
			cnt = i+1;
		}
	}
	printf("%d\n%d\n",max,cnt);
	return 0;
}
	
