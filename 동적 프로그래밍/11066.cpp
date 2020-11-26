#define INF 1000000000
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[501][501];
int book[501];
int sum[501];
int sol(int start, int end);

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();
	int TC;
	cin >> TC;
	while (TC--) {
		int K;
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> book[i];
			sum[i] = sum[i - 1] + book[i];
		}

		// �湮 ó��
		for (int i = 1; i <= K; i++) {
			for (int j = 1; j <= K; j++) {
				dp[i][j] = -1;
			}
		}
		
		cout << sol(1, K) << endl;
	}
}

int sol(int start, int end) {
	// ���۰� ���� ���ٸ� 0 ����
	if (start == end) { return 0; }
	// �̹� ���س��� ���̶�� dp�� ����
	if (dp[start][end] != -1) { return dp[start][end]; }
	// �Ѱ� ���� ���� �ΰ� ���ϱ�
	if (end == start + 1) return book[start] + book[end];

	dp[start][end] = INF;
	for (int i = start; i <= end; i++) {
		int temp = sol(start, i) + sol(i + 1, end) + sum[end] - sum[start - 1];
		dp[start][end] = min(dp[start][end], temp);
	}
	return dp[start][end];
}