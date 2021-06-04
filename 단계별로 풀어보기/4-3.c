#include <stdio.h>

int main()
{
	int origin,newValue;
	int a,b,c;
	int count = 1;
	scanf("%d",&origin);
	newValue = origin;
	while(1){
	a = newValue / 10;
	b = newValue  % 10;
	c = a + b;
	if(c>= 10){
		c -= 10;
	}
	newValue = 10*b + c;
	if(newValue == origin){
		break;
	}
	count++;
	}
	printf("%d\n",count);
	return 0;
}



