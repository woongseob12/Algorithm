#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, S, ans;
vector<int> num;
void dfs(int idx, int sum, int size);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		num.push_back(val);
	}
	sort(num.begin(), num.end());
	dfs(0, 0, 0);
	cout << ans << endl;
}

void dfs(int idx, int sum, int size) {
	if (idx == N) {
		if (sum == S && size != 0) {
			ans++;
		}
		return;
	}
	dfs(idx + 1, sum + num[idx], size + 1);
	dfs(idx + 1, sum, size);
}