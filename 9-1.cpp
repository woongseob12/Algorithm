#include <iostream>
using namespace std;

int main()
{
	int fixed, variable, price;
	cin >> fixed >> variable >> price;
	if (variable >= price) {
		cout << -1 << endl;
	}
	else {
		cout << fixed / (price - variable) + 1 << endl;
	}
}
