#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	stack<int> ans;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (!ans.empty() && temp == 0) {
			ans.pop();
		}
		else { ans.push(temp); }
	}
	int sum = 0;
	while (!ans.empty()) {
		sum += ans.top();
		ans.pop();
	}
	cout << sum;
}
