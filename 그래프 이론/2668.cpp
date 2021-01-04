#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, ans;
int num[101];
vector<int> res;
bool visit[101];
void dfs(int start, int curr);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[j] = false;
		}
		dfs(i, num[i]);
	}
	sort(res.begin(), res.end());

	cout << ans << '\n';
	for (int i = 0; i < ans; i++) {
		cout << res[i] << '\n';
	}
}

void dfs(int start, int curr) {
	if (start == curr) {
		ans++;
		res.push_back(start);
		return;
	}
	else {
		if (!visit[curr]) {
			visit[curr] = true;
			dfs(start, num[curr]);
		}
	}
}
