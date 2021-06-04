#include <iostream>
using namespace std;

int main()
{
	int score[5];
	for(int i=0; i< sizeof(score)/sizeof(score[0]); i++){
		cin>>score[i];
	}
	for(int i=0; i< sizeof(score)/sizeof(score[0]); i++){
		if(score[i] <= 40){
			score[i] = 40;
		}
	}
	int sum = 0;
	for(int i=0; i< sizeof(score)/sizeof(score[0]); i++){
		sum += score[i];
	}
	int avg = sum/(sizeof(score)/sizeof(score[0]));
	cout << avg;
}



