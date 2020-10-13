#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	vector<int> ans;
	ans.push_back(num[0]);
	for (int i = 1; i < n; i++) {
		if (ans.back() < num[i]) {
			ans.push_back(num[i]);
		}
		else {
			vector<int>::iterator iter = lower_bound(ans.begin(), ans.end(), num[i]);
			*iter = num[i];
		}
	}

	cout << ans.size() << endl;
}