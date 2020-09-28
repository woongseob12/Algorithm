#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, val, index = 0;
	cin >> n;

	vector<int> stack;
	vector<char> ans;

	for (int i = 0; i < n; i++) {
		cin >> val;
		if (val > index) {
			for (int i = index + 1; i <= val; i++) {
				stack.push_back(i);
				ans.push_back('+');
			}
			index = val;
			stack.pop_back();
			ans.push_back('-');
		}
		else {
			if (stack.back() != val) {
				cout << "NO" << endl;
				return 0;
			}
			stack.pop_back();
			ans.push_back('-');
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}