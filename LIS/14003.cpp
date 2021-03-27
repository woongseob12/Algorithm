#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000001;
int num[MAX], dp[MAX], idx;
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	
	vector<int> ans, s;
	ans.push_back(num[0]);
	for (int i = 1; i < n; i++) {
		if (ans.back() < num[i]) {
			ans.push_back(num[i]);
			dp[i] = ++idx;
		}
		else {
			int pos = lower_bound(ans.begin(), ans.end(), num[i]) - ans.begin();
			ans[pos] = num[i];
			dp[i] = pos;
		}
	}

	cout << idx + 1 << "\n";
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == idx) {
			s.push_back(num[i]);
			idx--;
		}
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		cout << s[i] << " ";
	}
}