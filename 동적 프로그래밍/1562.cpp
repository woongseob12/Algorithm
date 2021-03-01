#include <iostream>
#include <cstring>
#define MOD 1000000000
using namespace std;

int N;
int dp[101][10][1 << 10];
int sol(int depth, int num, int bit);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	
	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		memset(dp, -1, sizeof(dp));
		ans += sol(1, i, 1 << i);
		ans %= MOD;
	}

	cout << ans;
}

int sol(int depth, int num, int bit) {
	if (depth == N) {
		if (bit == (1 << 10) - 1) {
			return 1;
		}
		return 0;
	}

	int& ret = dp[depth][num][bit];
	if (ret != -1) return ret;

	ret = 0;
	if (num + 1 <= 9) { ret += sol(depth + 1, num + 1, bit | 1 << (num + 1)); }
	if (num - 1 >= 0) { ret += sol(depth + 1, num - 1, bit | 1 << (num - 1)); }

	ret %= MOD;
	return ret;
}

