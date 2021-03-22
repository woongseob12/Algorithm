#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 101
#define INF 987654321
using namespace std;

int N, M;
int arr[MAX][MAX];
bool visit[MAX];
vector<int> ans;
int bfs(int start);

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (arr[j][k] > arr[j][i] + arr[i][k]) {
					arr[j][k] = arr[j][i] + arr[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			ans.push_back(bfs(i));
		}
	}
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}

int bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true;
	vector<int> team;
	team.push_back(start);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (!visit[i] && arr[curr][i] != INF) {
				visit[i] = true;
				q.push(i);
				team.push_back(i);
			}
		}
	}
	int lastIdx = start, lastVal = INF;
	for (int i = 0; i < team.size(); i++) {
		int temp = 0;
		for (int j = 0; j < team.size(); j++) {
			if (team[i] == team[j]) { continue; }
			temp = max(temp, arr[team[i]][team[j]]);
		}
		if (lastVal > temp) {
			lastVal = temp;
			lastIdx = team[i];
		}
	}
	return lastIdx;
}
