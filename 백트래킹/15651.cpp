#pragma warning (disable : 4996)
#define MAX_SIZE 8
#include <cstdio>

int n, m;
int res[MAX_SIZE] = { 0, };
bool visit[MAX_SIZE] = { 0, };
void dfs(int cnt);

int main()
{
	scanf("%d %d", &n, &m);
	dfs(0);
}

void dfs(int cnt)
{
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			res[cnt] = i;
			dfs(cnt + 1);
			visit[i] = true;
		}
		visit[i] = false;
	}
}
