#include <iostream>
using namespace std;

int main()
{
	int line;
	cin>>line;
	for(int i=0; i< line*2 - 1; i++){
		if(i<=line){
			for(int j= 0; j<i;j++){
				cout<<"*";
			}
		}
		else{
			for(int j = i; j < line*2 -1; j++){
				cout<<"*";
			}
		}
	}
}
