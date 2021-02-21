#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 16
#define INF 987654321
using namespace std;

int N;
double W[MAX][MAX];
double dp[MAX][1 << MAX];
double dist(pair<int, int> a, pair<int, int> b);
double TSP(int curr, int bit);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	vector<pair<int, int>> city(N);
	for (int i = 0; i < N; i++) {
		cin >> city[i].first >> city[i].second;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			W[i][j] = dist(city[i], city[j]);
		}
	}
	cout << fixed << setprecision(6) << TSP(0, 1) << "\n";
}

double dist(pair<int, int> a, pair<int, int> b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double TSP(int curr, int bit) {
	if (bit == (1 << N) - 1) { return W[curr][0]; }

	double& ret = dp[curr][bit];
	if (dp[curr][bit] != 0) { return dp[curr][bit]; }
	ret = INF;
	for (int i = 0; i < N; i++) {
		if (bit & (1 << N) || W[curr][i] == 0) { continue; }
		double cost = TSP(i, bit | (1 << i)) + W[curr][i];
		ret = min(ret, cost);
	}
	return ret;
}
