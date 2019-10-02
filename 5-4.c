#include <stdio.h>

int main()
{
	int a,b,c;
	int res;
	int k;
	int i,j,cal;
	int num[10] = {0,};
	scanf("%d %d %d",&a,&b,&c);
	res = a* b* c;
	if((res >= 1000000)&&(res <=9999999)){
		num[0] = -2;
	}
	else if((res >= 10000000)&&(res <=99999999)){
		num[0] = -1;
	}
	else {
		k = res /100000000;
		num[k]++;
	}	
	for(i = 10;i <= 1000000000; i*=10){
		cal = res % i;
		for(j=0;j<10;j++){
			if(j == cal*10/i){
				num[j]++;
			}
		}
		res -= cal;
	}
	for(j = 0; j< 10; j++)
	{
		printf("%d\n",num[j]);
	}
	return 0;
}
	
		

