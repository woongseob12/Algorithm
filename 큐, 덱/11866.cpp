#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	queue<int> sel;
	queue<int> ans;
	for (int i = 1; i <= n; i++) {
		sel.push(i);
	}
	while (!sel.empty()) {
		// k - 1 ȸ
		for (int i = 1; i < k; i++) {
			int temp = sel.front();
			sel.pop();
			sel.push(temp);
		}
		// kȸ
		ans.push(sel.front());
		sel.pop();
	}
	cout << "<";
	while (!ans.empty()) {
		if (ans.size() == 1) {
			cout << ans.front() << ">";
			ans.pop();
		}
		else {
			cout << ans.front() << ", ";
			ans.pop();
		}
	}
}