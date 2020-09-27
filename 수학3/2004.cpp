#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int num_5 = 0;
	for (long long i = 5; i <= n; i *= 5) {
		num_5 += n / i;
	}
	for (long long i = 5; i <= n - m; i *= 5) {
		num_5 -= (n - m) / i;
	}
	// 분모
	for (long long i = 5; i <= m; i *= 5) {
		num_5 -= m / i;
	}

	int num_2 = 0;
	for (long long i = 2; i <= n; i *= 2) {
		num_2 += n / i;
	}
	for (long long i = 2; i <= n - m; i *= 2) {
		num_2 -= (n - m) / i;
	}
	// 분모
	for (long long i = 2; i <= m; i *= 2) {
		num_2 -= m / i;
	}

	cout << min(num_5, num_2) << endl;
}