#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int ans;
int student[100001];
bool visit[100001], cycle[100001];
void dfs(int start, int curr);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> student[i];
		}
		ans = 0;
		memset(visit, false, sizeof(visit));
		memset(cycle, false, sizeof(cycle));
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				visit[i] = true;
				dfs(i, student[i]);
			}
		}
		cout << n - ans << '\n';
	}
}

void dfs(int start, int next) {
	if (!visit[next]) {
		visit[next] = true;
		dfs(next, student[next]);
	}
	else {
		if (!cycle[next]) {
			for (int i = next; i != start; i = student[i]) {
				ans++;
			}
			ans++;
		}
	}
	cycle[start] = true;
}
