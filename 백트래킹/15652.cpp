#pragma warning (disable :4996)
#define MAX_SIZE 9
#include <cstdio>

int res[MAX_SIZE] = { 0, };
bool visit[MAX_SIZE] = { 0, };
int n, m;
void dfs(int cnt, int idx);

int main()
{
	scanf("%d %d", &n, &m);
	dfs(0, 1);
}

void dfs(int cnt, int idx)
{
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
		return;
	}

	for (int i = idx; i <= n; i++) {
		if (!visit[i]) {
			res[cnt] = i;
			dfs(cnt + 1, idx);
			visit[i] = true;
		}
		visit[i] = false;
		idx++;
	}
}