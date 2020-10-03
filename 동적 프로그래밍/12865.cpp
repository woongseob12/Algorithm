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
		// <����, ��ġ>
		cin >> item[i].first >> item[i].second;
	}
	
	for (int i = 1; i <= N; i++) {
		// N�� ����(�ִ� ����) ��ŭ ����
		for (int j = 1; j <= K; j++) {
			// ���� ���� �־� ��
			dp[i][j] = dp[i - 1][j];
			if (j >= item[i].first) {	// ���� ������ �ִٸ�
				dp[i][j] = max(dp[i - 1][j - item[i].first] + item[i].second, dp[i - 1][j]);
			}
		}
	}
	cout << dp[N][K] << endl;
}
