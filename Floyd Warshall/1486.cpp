#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 25
#define INF 987654321
using namespace std;

int N, M, T, D;
int arr[MAX][MAX], d[MAX * MAX][MAX * MAX];
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
void floyd();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> T >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char val;
			cin >> val;
			if (val >= 'A' && val <= 'Z') {
				arr[i][j] = val - 'A';
			}
			else {
				arr[i][j] = (val - 'a') + 26;
			}
		}
	}
	
	floyd();

	int ans = 0;
	for (int i = 0; i < N * M; i++) {
		if (d[0][i] + d[i][0] <= D) {
			ans = max(ans, arr[i / M][i % M]);
		}
	}
	cout << ans;
}

void floyd() {
	for (int i = 0; i < N * M; i++) {
		for (int j = 0; j < N * M ; j++) {
			if (i == j) {
				d[i][j] = 0;
			}
			else {
				d[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				int start = i * M + j;
				int dest = ny * M + nx;
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) { continue; }
				int diff = abs(arr[ny][nx] - arr[i][j]);
				if (diff > T) { continue; }
				if (arr[ny][nx] > arr[i][j]) {
					d[start][dest] = diff * diff;
				}
				else {
					d[start][dest] = 1;
				}
			}
		}
	}

	for (int i = 0; i < N * M; i++) {
		for (int j = 0; j < N * M; j++) {
			for (int k = 0; k < N * M; k++) {
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
}
