#define MAX 103
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
bool visit[MAX];
vector<int> graph[MAX];
int cal(pair<int, int> a, pair<int, int> b);
void dfs(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		cin >> n;
		vector<pair<int, int>> pos(n + 2);
		for (int i = 0; i < n + 2; i++) {
			graph[i].clear();
			visit[i] = false;
			cin >> pos[i].first >> pos[i].second;
		}

		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < n + 2; j++) {
				if (cal(pos[i], pos[j]) <= 1000) {
					graph[i].push_back(j);
				}
			}
		}
		dfs(0);

		if (visit[n + 1]) {
			cout << "happy\n";
		}
		else {
			cout << "sad\n";
		}
	}

}

int cal(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int n) {
	visit[n] = true;
	for (int i = 0; i < (int)graph[n].size(); i++) {
		int next = graph[n][i];
		if (!visit[next]) {
			dfs(next);
		}
	}
}