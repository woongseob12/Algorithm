#include <iostream>
#include <string>
using namespace std;

int dp[1000000];
void init();

int main()
{
	init();
	int N, M, ans = 0;
	cin >> N >> M;
	string s;
	cin >> s;

	for (int i = 2; i < M; i++) {
		if (s[i] == 'I' && s[i - 1] == 'O' && s[i - 2] == 'I') {
			dp[i] = dp[i - 2] + 1;
		}
		else {
			dp[i] = 0;
		}
	}

	for (int i = 2 * N + 1; i < M; i++) {
		if (dp[i] >= N) {
			ans++;
		}
	}
	cout << ans << endl;
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}