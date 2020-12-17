#define LOTTO 6
#include <iostream>
#include <vector>
using namespace std;

int TC;
vector<int> num, valid;
void dfs(int idx, int cnt);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> TC;
	while (TC != 0) {
		num.clear();
		valid.clear();
		for (int i = 0; i < TC; i++) {
			int val;
			cin >> val;
			num.push_back(val);
		}
		dfs(0, 0);
		cout << '\n';
		cin >> TC;
	}
}

void dfs(int idx, int cnt) {
	if (cnt == LOTTO) {
		for (int i = 0; i < LOTTO; i++) {
			cout << valid[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = idx; i < (int)num.size(); i++) {
		valid.push_back(num[i]);
		dfs(i + 1, cnt + 1);
		valid.pop_back();
	}
}