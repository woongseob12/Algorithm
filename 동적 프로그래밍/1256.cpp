#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string ans = "";
long long dp[202][101];	// 만들 수 있는 경우의 수
void nextWord(int A, int Z, int next);

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j || j == 0) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = min((int)(dp[i - 1][j - 1] + dp[i - 1][j]), 1000000000);
			}
		}
	}
	if (K > dp[N + M][M]) { cout << "-1" << endl; }
	else {
		nextWord(N - 1, M, K);
		cout << ans << endl;
	}
}

void nextWord(int A, int Z, int next)
{
	if (A == 0) {
		for (int i = 0; i < Z; i++) {
			ans += 'z';
		}
		return;
	}
	if (Z == 0) {
		for (int i = 0; i < A; i++) {
			ans += 'a';
		}
		return;
	}
	int idx = dp[A - 1][Z] + dp[A][Z - 1];
	if (next <= idx) {
		ans += "a";
		nextWord(A- 1, Z, next);
	}
	else {
		ans += "z";
		nextWord(A, Z-1, next - idx);
	}
}