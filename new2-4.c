#include <stdio.h>
int main()
{
	int x,y;
	int res;
	scanf("%d %d", &x, &y);
	if(x>0){
		if(y>0){
			res = 1;}
		else {
			res = 4;}
	}
	else{
		if(y>0){
			res = 2;}
		else{
			res = 3;}
	}
	printf("%d\n",res);
	return 0;
}
