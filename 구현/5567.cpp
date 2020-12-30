#include <iostream>
#include <vector>
using namespace std;

int n, m, ans;
vector<int> friendship[501];
bool visit[501];
void sol(int num);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		friendship[a].push_back(b);
		friendship[b].push_back(a);
	}

	for (int i = 0; i < (int)friendship[1].size(); i++) {
		sol(friendship[1][i]);
	}
	cout << ans << '\n';
}

void sol(int num) {
	if (!visit[num]) {
		ans++;
		visit[num] = true;
	}
	for (int i = 0; i < (int)friendship[num].size(); i++) {
		if (!visit[friendship[num][i]] && friendship[num][i] != 1) {
			ans++;
			visit[friendship[num][i]] = true;
		}
	}
}