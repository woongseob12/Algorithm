#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> ans;
	for (int i = 0; i < 7; i++) {
		int val;
		cin >> val;
		if (val % 2 != 0) {
			ans.push_back(val);
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.empty()) {
		cout << -1 << endl;
	}
	else {
		int sum = 0;
		for (int i = 0; i < (int)ans.size(); i++) {
			sum += ans[i];
		}
		cout << sum << '\n' << ans[0] << endl;
	}

}