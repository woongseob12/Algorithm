#pragma warning (disable : 4996)
#define MAX_SIZE 15
#include <cstdio>
#include <cmath>

int n, res;
int chess[MAX_SIZE];
void dfs(int cnt);

int main()
{
	scanf("%d", &n);
	dfs(0);
	printf("%d\n", res);
}

void dfs(int cnt) {
	if (cnt == n) {
		res++;
		return;
	}

	for (int i = 0; i < n; i++) {
		chess[cnt] = i;
		bool valid = true;
		for (int j = 0; j < cnt; j++) {
			if (chess[j] == chess[cnt] || abs(chess[j] - chess[cnt]) == cnt - j) {
				valid = false;
			}
		}
		if (valid) {
			dfs(cnt + 1);
		}
	}
}