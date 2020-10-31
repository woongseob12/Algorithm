#include <iostream>
using namespace std;

int N;
long long dp[101][101];
int map[101][101];

int main() 
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	dp[1][1] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == N && j == N) {
				cout << dp[N][N] << endl;
				break;
			}
			if (j + map[i][j] <= N) {	// 오른쪽
				dp[i][j + map[i][j]] += dp[i][j];
			}
			if (i + map[i][j] <= N) {	// 아래쪽
				dp[i + map[i][j]][j] += dp[i][j];
			}
		}
	}
}

