#include <iostream>
#include <vector>
#include <queue>
#define ARY_SIZE 1001
using namespace std;

int N, M, V;
int map[ARY_SIZE][ARY_SIZE];
bool visit[ARY_SIZE];
bool check[ARY_SIZE];
void init();
void dfs(int n);
void bfs(int n);

int main()
{
	init();
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}
	dfs(V);
	cout << endl;
	bfs(V);
	cout << endl;
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void dfs(int n)
{
	cout << n << " ";
	visit[n] = true;
	for (int i = 1; i <= N; i++) {
		if (map[n][i] == 1 && !visit[i]) {
			dfs(i);
		}
	}
}

void bfs(int n)
{
	queue<int> q;
	check[n] = true;
	q.push(n);

	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		cout << temp << " ";
		for (int i = 1; i <= N; i++) {
			if (map[temp][i] == 1 && !check[i]) {
				check[i] = true;
				q.push(i);
			}
		}
	}
}