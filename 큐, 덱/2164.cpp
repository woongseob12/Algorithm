#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;

	queue<int> ans;
	for (int i = 1; i <= n; i++) {
		ans.push(i);
	}

	while (ans.size() != 1) {
		ans.pop();
		if (ans.size() == 1) {
			break;
		}
		int temp = ans.front();
		ans.push(temp);
		ans.pop();
	}
	cout << ans.front() << endl;
}