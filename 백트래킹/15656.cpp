#define MAX_SIZE 9
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int>ary;
int num[MAX_SIZE];
void dfs(int cnt);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		ary.push_back(val);
	}
	sort(ary.begin(), ary.end());
	dfs(0);
}

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << num[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		num[cnt] = ary[i];
		dfs(cnt + 1);
	}
}

