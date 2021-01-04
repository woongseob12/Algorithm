#include <iostream>
using namespace std;

int a, b, c;
int dp[21][21][21];
int w(int a, int b, int c);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;
	while (a != -1 || b != -1 || c != -1) {
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
		cin >> a >> b >> c;
	}
}

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) { return 1; }
	if (a > 20 or b > 20 or c > 20) { return w(20, 20, 20); }

	if (dp[a][b][c] != 0) { return dp[a][b][c]; }
	int &ret = dp[a][b][c];
	if (a < b && b < c) { return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c); }
	return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
