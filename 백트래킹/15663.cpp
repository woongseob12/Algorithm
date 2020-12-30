#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int N, M; 
int num[8];
int ary[8];
bool visit[8];
set<string> s;
void dfs(int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	dfs(0);

}

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << ary[i] << " ";
		}
		cout << '\n';
		return;
	}

	bool used[10001] = { false, };
	for (int i = 0; i < N; i++) {
		if (!visit[i] && !used[num[i]]) {
			visit[i] = true;
			used[num[i]] = true;
			ary[cnt] = num[i];
			dfs(cnt + 1);
			visit[i] = false;
		}
	}
}