#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	stack<int> pipe;
	int ans = 0;
	for (int i = 0; i < (int)str.size(); i++) {
		if (str[i] == '(') {
			if (str[i + 1] == ')') {
				ans += pipe.size();
			}
			else {
				pipe.push(i);
			}
		}
		else {
			if (str[i - 1] == '(') {
				continue;
			}
			else {
				ans += 1;
				pipe.pop();
			}
		}
	}
	cout << ans << endl;
}