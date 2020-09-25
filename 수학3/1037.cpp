#include <iostream>
#include <algorithm>
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
		ans.push_back(temp);
	}
	sort(ans.begin(), ans.end());
	cout << ans.front() * ans.back() << endl;
}