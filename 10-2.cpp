#include <iostream>
using namespace std;

int main()
{
	int min, max, minPrime, i, j;
	cin >> min >> max;
	bool havePrime = false;
	bool firstPrime = false;
	int sum = 0;

	for (i = min; i <= max; i++) {
		for (j = 2; j < i; j++) {
			if (i % j == 0) {
				break;
			}
		}
		if (j == i) {
			havePrime = true;
			sum += i;
		}
		if (havePrime == true && firstPrime == false) {
			minPrime = i;
			firstPrime = true;
		}
	}
	if (!havePrime) {
		cout << -1 << endl;
	}
	else {
		cout << sum << "\n" << minPrime << endl;
	}
}
