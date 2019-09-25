#include <stdio.h>

int main()
{
	int origin,new;
	int a,b,c;
	int count = 1;
	scanf("%d",&origin);
	new = origin;
	while(1){
	a = new / 10;
	b = new  % 10;
	c = a + b;
	if(c>= 10){
		c -= 10;
	}
	new = 10*b + c;
	if(new == origin){
		break;
	}
	count++;
	}
	printf("%d\n",count);
	return 0;
}



