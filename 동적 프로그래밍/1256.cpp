#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string ans = "";
int dp[101][101];	
void nextWord(int A, int Z, int next);

int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = min(dp[i][j - 1] + dp[i - 1][j], 1000000000);
			}
		}
	}

	if (K > dp[N][M]) { cout << "-1" << endl; }
	else {
		nextWord(N, M, K);
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

	int idx = dp[A - 1][Z];
	if (next <= idx) {
		ans += "a";
		nextWord(A- 1, Z, next - 1);
	}
	else {
		ans += "z";
		nextWord(A, Z-1, next - idx);
	}
}
