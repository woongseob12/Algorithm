#include <iostream>
using namespace std;

int main()
{
	int burger[3];
	int beverage[2];

	cin >> burger[0] >> burger[1] >> burger[2];
	cin >> beverage[0] >> beverage[1];

	int burgerMin = burger[0];
	int beverageMin = beverage[0];
	for (int i = 0; i < sizeof(burger) / sizeof(burger[0]); i++) {
		if (burgerMin > burger[i]) {
			burgerMin = burger[i];
		}
	}
	for (int i = 0; i < sizeof(beverage) / sizeof(beverage[0]); i++) {
		if (beverageMin > beverage[i]) {
				beverageMin = beverage[i];
		}
	}
	int sum;
	sum = burgerMin + beverageMin - 50;
	cout << sum;
}





