#include <stdio.h>

int main()
{
	int music[8];
	int i;
	int sel=0;
	for(i=0;i<8;i++){
		scanf("%d",&music[i]);
	}
	if(music[0] == 1){
		i = 0;
		while((i<8)&&(music[i]==i+1)){ //while 조건문 순서 조심 music[i]조건이 늦게 나올경우 미예약영역 읽어들임
		i++;
		}
		if (i== 8){
			sel = 1;
		}
	}
	else if(music[0] == 8){
		i = 0;
		while((i<8)&&(music[i] == 8 -i)){
			i++;
		}
		if (i==8){
			sel = 2;
		}
	}
	else{
		sel = 0;
	}
	switch (sel){
	case 0 : printf("mixed\n");break;
	case 1 : printf("ascending\n");break;
	case 2 : printf("descending\n");break;
	default : break;
	}
	return 0;
}



		
