#include <iostream>
using namespace std;

int N, M;
int graph[1001][1001];
int visit[1001];
void init();
void dfs(int n);

int main()
{
	init();
	cin >> N >> M;
	int ans = 0;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u][v] = graph[v][u] = 1;
	}
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			ans++;
			dfs(i);
		}
	}
	cout << ans << endl;
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void dfs(int n)
{
	visit[n] = true;
	for (int i = 1; i <= N; i++) {
		if (!visit[i] && graph[n][i] == 1) {
			visit[i] = true;
			dfs(i);
		}
	}
}