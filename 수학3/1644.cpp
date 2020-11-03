#include <iostream>
#include <vector>
using namespace std;

vector<int> primeNum;

int main()
{
	int n;
	cin >> n;

	vector<bool> prime(n + 1, true);
	for (int i = 2; i * i <= n; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				prime[j] = false;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (prime[i]) {
			primeNum.push_back(i);
		}
	}
	//투 포인터 알고리즘
	int start = 0, end = 0, ans = 0, sum = 0;
	while (true) {
		if (sum >  n) {
			sum -= primeNum[start++];
		}
		else if (end == primeNum.size()) {
			break;
		}
		else {
			sum += primeNum[end++];
		}

		if (sum == n) {
			ans++;
		}
	}
	cout << ans << endl;
}

