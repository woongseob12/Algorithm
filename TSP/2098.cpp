#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 16
#define INF 987654321
using namespace std;

int N;
int arr[MAX][MAX];
int dp[MAX][1 << MAX];
int TSP(int curr, int bit);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << TSP(0, 1) << "\n";
}

int TSP(int curr, int bit) {
	// 모든곳을 방문 했다면 (1000...0  - 1 = 01111...1)
	if (bit == (1 << N) - 1) {
		if (arr[curr][0] != 0) {
			return arr[curr][0];
		}
		return INF;
	}
	if (dp[curr][bit] != -1) {
		return dp[curr][bit];
	}
	dp[curr][bit] = INF;
	for (int i = 0; i < N; i++) {
		// 갔거나 , 갈 길이 없으면
		if (bit & (1 << i) || arr[curr][i] == 0) continue;
		int cost = TSP(i, bit | (1 << i)) + arr[curr][i];
		dp[curr][bit] = min(dp[curr][bit], cost);
	}
	return dp[curr][bit] ;
}