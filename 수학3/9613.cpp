#include <iostream>
using namespace std;

int num[100];
int gcd(int a, int b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		int n;
		long long ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += gcd(num[i], num[j]);
			}
		}
		cout << ans << '\n';
	}
}  

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}