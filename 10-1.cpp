#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int cnt = 0;
	for (int i = 0; i < num; i++) {
		int prime;
		cin >> prime;
		bool isPrime = true;
		for (int j = 2; j < prime; j++) {
			if (prime % j == 0) {
				isPrime = false;
			}
		}
		if (isPrime && prime != 1) {
			cnt++;
		}
	}
	cout << cnt << endl;
}
