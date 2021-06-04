#include <stdio.h>
#include <string.h>

int main()
{
	char alpha[100];
	int len,i,j,cnt;
	
	scanf("%s",alpha);
	len = strlen(alpha);
	int location[26] = {0,};
	int startAscii = 97;
	for (i = 0; i<26;i++){
		cnt = 0;
		for (j = 0; j <len ; j++){
			if ((char)startAscii == alpha[j]){
				location[i] = cnt;
				break;
			}
			else {
				cnt++;
			}
			location[i] = -1;
		}
		startAscii++;
	}
	for (i = 0; i < 26; i++){
		printf("%d ",location[i]);
	}
	printf("\n");
	return 0;
}


