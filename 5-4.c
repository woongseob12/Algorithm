#include <stdio.h>

int main()
{
	int a,b,c;
	int res,nRes;
	int i,j,k,cal;
	int num[10] = {0,};
	scanf("%d %d %d",&a,&b,&c);
	res = a*b*c;
	nRes = res;
	if(res<=99999999){
		for(i = 10;i<=res*10;i*=10){
			cal = nRes % i;
			for(j=0;j<10;j++){
				if(j == cal*10/i){
					num[j]++;
				}
			}
			nRes -= cal;
		}
	}
	else{
		for(i = 10;i<=res;i*=10){
			cal = nRes % i;
			for(j=0;j<10;j++){
				if(j == cal*10/i){
					num[j]++;
				}
			}
			nRes -= cal;
			k = res / 100000000;
		}
		num[k]++;
	}
	for(j = 0; j< 10; j++)
	{
		printf("%d\n",num[j]);
	}
	return 0;
}
	
		

