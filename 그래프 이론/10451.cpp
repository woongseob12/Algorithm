#include <iostream>
#include <vector>
using namespace std;

int N;
int ary[1001];
bool visit[1001];
void dfs(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin >> TC;
	while (TC--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> ary[i];
			visit[i] = false;
		}

		int ans = 0;

		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				ans++;
				dfs(i);
			}
		}
		cout << ans << '\n';
	}
}

void dfs(int n) {
	if (visit[n]) {
		return;
	}
	visit[n] = true;
	dfs(ary[n]);
}