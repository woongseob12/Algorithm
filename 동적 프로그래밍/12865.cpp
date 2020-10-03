#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101][100001];
pair<int, int> item[101];

int main()
{
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		// <무게, 가치>
		cin >> item[i].first >> item[i].second;
	}
	
	for (int i = 1; i <= N; i++) {
		// N의 개수(최대 개수) 만큼 넣음
		for (int j = 1; j <= K; j++) {
			// 이전 것을 넣어 줌
			dp[i][j] = dp[i - 1][j];
			if (j >= item[i].first) {	// 넣을 공간이 있다면
				dp[i][j] = max(dp[i - 1][j - item[i].first] + item[i].second, dp[i - 1][j]);
			}
		}
	}
	cout << dp[N][K] << endl;
}
