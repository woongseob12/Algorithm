#include <iostream>
using namespace std;
int N, M, ans;
int net[101][101];
bool visit[101];
void init();
void dfs(int n);

int main()
{
	cin >> N >> M;


	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		net[a][b] = net[b][a] = 1;
	}

	dfs(1);
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
		if (!visit[i] && net[n][i] == 1) {
			ans++;
			dfs(i);
		}
	}
}