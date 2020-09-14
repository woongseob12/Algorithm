#pragma warning (disable : 4996)
#define MAX_SIZE 9
#include <cstdio>
#include <vector>
using namespace std;

vector<int> res(MAX_SIZE, 0);
vector<bool> visit(MAX_SIZE, false);
int N, M;
void dfs(int cnt);

int main()
{
	scanf("%d %d", &N, &M);
	dfs(0);
}

void dfs(int cnt)
{
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			res[cnt] = i;
			dfs(cnt + 1);
			visit[i] = false;
		}
	}
}