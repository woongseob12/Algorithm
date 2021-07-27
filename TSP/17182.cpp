#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 10
#define INF 9999
using namespace std;

int N, K, ans;
int dp[MAX][1 << MAX];
vector<vector<int>> time;
void input();
void solve();
void floyd();
int tsp(int curr, int bit);
void output(); 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
	output();
}

void input() {
	cin >> N >> K;
	time.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> time[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
}

void solve() {
	floyd();
	ans = tsp(K, 1 << K);
}

void floyd() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (j == i || i == k) continue;
				time[j][k] = min(time[j][k], time[j][i] + time[i][k]);
			}
		}
	}
}

int tsp(int curr, int bit) {
	if (bit == (1 << N) - 1) {
		return 0;
	}

	int &ret = dp[curr][bit];
	if (ret != -1) return ret;
	ret = INF;
	
	for (int i = 0; i < N; i++) {
		if (bit & (1 << i) || curr == i) continue;
		int cost = tsp(i, bit | (1 << i)) + time[curr][i];
		ret = min(ret, cost);
	}
	return ret;
}

void output() {
	cout << ans;
}