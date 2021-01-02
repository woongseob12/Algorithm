#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> num;
int res[8];
bool visit[8];
void dfs(int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		num.push_back(val);
	}
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	N = num.size();
	dfs(0);
}

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << res[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		if (cnt > 0 && res[cnt - 1] > num[i]) { continue; }
		res[cnt] = num[i];
		dfs(cnt + 1);
	}
}