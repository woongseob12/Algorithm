#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[20001];
int color[20001];
bool flag = true;
void dfs(int node, int c);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int K;
	cin >> K;
	while (K--) {
		int V, E;
		cin >> V >> E;
		for (int i = 1; i <= V; i++) {
			graph[i].clear();
			color[i] = 0;
		}
		flag = true;
		for (int i = 0; i < E; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for (int i = 1; i <= V; i++) {
			if (color[i] == 0) {
				dfs(i, 1);
			}
			else {
				dfs(i, color[i]);
			}
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}

void dfs(int node, int c) {
	color[node] = c;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (color[next] == 0) {
			dfs(next, c * -1);
		}
		else if (color[next] == color[node]) {
			flag = false;
		}
	}
}