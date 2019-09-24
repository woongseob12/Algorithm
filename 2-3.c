#include <stdio.h>

int main()
{
	int year;
	int check = 0;
	scanf("%d",&year);
	if(year%400 == 0){
		check = 1;
	}
	else if((year%4 == 0)&&(year%100 != 0)){
		check = 1;
	}
	printf("%d\n",check);
	return 0;
}
