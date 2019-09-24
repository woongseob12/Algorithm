#include <stdio.h>

int main()
{
	int res[3];
	int temp;
	int i,j;
	scanf("%d %d %d",&res[0],&res[1],&res[2]);
	for (i = 0;i<3;i++)
	{
		for(j = i +1;j<3;j++)
		{
			if(res[i]>res[j])
			{
				temp =res[i];
				res[i] = res[j];
				res[j] = temp;
			}
		}

	}
	printf("%d\n",res[1]);
	return 0;
}

		
