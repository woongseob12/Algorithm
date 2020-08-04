#include <iostream>
using namespace std;

int main()
{
	int burger[3];
	int beverage[2];
	int burgerMin, beverageMin;

	for(int i = 0;i<sizeof(burger)/sizeof(burger[0]); i++){
		cin>>burger[i];
	}
	for(int i=0; i<sizeof(beverage)/sizeof(beverage[0]);i++){
		cin>>beverage[i];
	}
	for(int i=0; i<sizeof(burfer)/sizeof(burger[0]); i++){
		if(i=0){
			burgerMin = burger[i];
		}
		else{
			if(burgerMin<burger[i]){
				burgerMin = burger[i];
			}
		}
	}
	for(int i=0; i<sizeof(berverage)/sizeof(berverage[0]); i++){
		if(i=0){
			beverageMin = beverage[i];
		}
		else{
			if(beverageMin<beverage[i]){
				beverageMin = beverage[i];
			}
		}
	}
	int sum;
	sum = burgerMin + beverageMin - 50;
	cout<<sum;
}





