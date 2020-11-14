#include <iostream>
#include <vector>
using namespace std;

int ary[1025][1025];
int dp[1025][1025];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, TC;
	cin >> N >> TC;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> ary[i][j];
			if (j == 1) {
				dp[i][j] = ary[i][j];
			}
			else {
				dp[i][j] = dp[i][j - 1] + ary[i][j];
			}
		}
	}

	while (TC--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = 0;
		while (true) {
			ans += dp[x1][y2] - dp[x1][y1 - 1];
			if (x1 == x2) { break; }
			x1++;
		}
		cout << ans << '\n';
	}
}