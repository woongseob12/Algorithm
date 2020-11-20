#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		int N;
		cin >> N;
		vector<int> wood(N);
		for (int i = 0; i < N; i++) {
			cin >> wood[i];
		}
		sort(wood.begin(), wood.end());

		priority_queue<int> down;
		priority_queue < int, vector<int>, greater<int>> up;
		for (int i = 0; i < wood.size(); i++) {
			if (i % 2 == 0) {
				up.push(wood[i]);
			}
			else {
				down.push(wood[i]);
			}
		}
		vector<int > ans;
		while (!up.empty()) {
			ans.push_back(up.top());
			up.pop();
		}
		while (!down.empty()) {
			ans.push_back(down.top());
			down.pop();
		}
		int diff = 0;
		for (int i = 0; i < N; i++) {
			if (i == N - 1) {
				diff = max(diff, abs(ans[i] - ans[0]));
			}
			else {
				diff = max(diff, abs(ans[i + 1] - ans[i]));
			}
		}
		cout << diff << endl;
	}
}