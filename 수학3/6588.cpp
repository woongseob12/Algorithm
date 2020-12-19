#define MAX 1000001
#include <iostream>
#include <vector>
using namespace std;

bool prime[MAX];
vector<int> primeNum;
void valid();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	valid();

	while (n != 0) {
		bool goldbach = false;
		for (int i = 0; primeNum[i] < n; i++) {
			if (!prime[n - primeNum[i]]) {
				cout << n << " = " << primeNum[i] << " + " << n - primeNum[i] << '\n';
				goldbach = true;
				break;
			}
		}
		if (!goldbach) {
			cout << "Goldbach's conjecture is wrong.\n";
		}
		cin >> n;
	}
}

void valid() {
	for (int i = 2; i * i < MAX; i++) {
		if (!prime[i]) { 
			for (int j = i * i; j < MAX; j += i) {
				prime[j] = true;
			}
		}
	}

	for (int i = 3; i < MAX; i++) {
		if (!prime[i]) {
			primeNum.push_back(i);
		}
	}
}