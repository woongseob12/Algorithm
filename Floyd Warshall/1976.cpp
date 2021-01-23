#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, M;
int map[201][201];
int d[201][201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	vector<int> plan(M);
	for (int i = 0; i < M; i++) {
		cin >> plan[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (map[j][i] + map[i][k] == 2) {
					map[j][k] = 1;
				}
			}
		}
	}

	bool able = true;
	for (int i = 0; i < M - 1; i++) {
		if (plan[i] != plan[i + 1]) {
			if (map[plan[i]][plan[i + 1]] == 0) {
				able = false;
				break;
			}
		}
	}
	if (able) { cout << "YES"; }
	else { cout << "NO"; }
}
