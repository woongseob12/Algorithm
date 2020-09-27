#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (!ans.empty() && temp == 0) {
			ans.pop_back();
		}
		else {
			ans.push_back(temp);
		}
	}
	int sum = 0;
	for (int i = 0; i < (int)ans.size(); i++) {
		sum += ans[i];
	}
	cout << sum << endl;
}