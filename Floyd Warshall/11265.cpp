#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> cost;
vector<vector<int>> canArrive;
void input();
void solve();
void floyd();
void check();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}

void input() {
	cin >> N >> M;
	cost.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}
	canArrive.resize(M, vector<int>(3, 0));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> canArrive[i][j];
		}
	}
}

void solve() {
	floyd();
	check();
}

void floyd() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
			}
		}
	}
}

void check() {
	for (int i = 0; i < M; i++) {
		if (cost[canArrive[i][0] - 1][canArrive[i][1] - 1] <= canArrive[i][2]) {
			cout << "Enjoy other party\n";
		}
		else {
			cout << "Stay here\n";
		}
	}
}