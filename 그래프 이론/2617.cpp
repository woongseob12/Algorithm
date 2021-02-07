#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> heavy[100], light[100];
bool notMid[100], visit[100];
int N, M;
int dfs1(int start);
int dfs2(int start);

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int h, l;
		cin >> h >> l;
		heavy[h].push_back(l);
		light[l].push_back(h);
	}
	// 풀이
	for (int i = 1; i <= N; i++) {
		memset(visit, false, sizeof(visit));
		if (dfs1(i) > (N + 1) / 2) notMid[i] = true;
		memset(visit, false, sizeof(visit));
		if (dfs2(i) > (N + 1) / 2) notMid[i] = true;
	}

	// 출력
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (notMid[i]) {
			ans++;
		}
	}
	cout << ans;
}

int dfs1(int start) {
	int n = 1;

	for (int i = 0; i < heavy[start].size(); i++) {
		if (!visit[heavy[start][i]]) {
			visit[heavy[start][i]] = true;
			n += dfs1(heavy[start][i]);
		}
	}
	return n;
}

int dfs2(int start) {
	int n = 1;

	for (int i = 0; i < light[start].size(); i++) {
		if (!visit[light[start][i]]) {
			visit[light[start][i]] = true;
			n += dfs2(light[start][i]);
		}
	}
	return n;
}
