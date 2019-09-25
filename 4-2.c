#include <stdio.h>

int main()
{
	int a,b;
	while(1){
		scanf("%d %d",&a,&b);
		if((a==!EOF)||(b==!EOF)){
			break;
		}
		printf("%d\n",a+b);
	}
	return 0;
}

