#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int miro[1001][1001];
int dp[1001][1001];

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> miro[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1])) + miro[i][j];
		}
	}
	cout << dp[N][M] << endl;
}
