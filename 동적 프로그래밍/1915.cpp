#pragma warning (disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int ary[1001][1001];
int dp[1001][1001];
void input();
void square(int x, int y);

int main()
{
	input();
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			square(i, j);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans * ans << endl;
}

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int val;
			scanf("%1d", &val);
			ary[i][j] = val;
		}
	}
}

void square(int i, int j)
{
	if (ary[i][j] != 0) {
		dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
	}
	else {
		dp[i][j] = 0;
	}
}

