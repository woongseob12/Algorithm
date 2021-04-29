#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, ans = 0;
	cin >> n;

	while (n--) {
		string str;
		cin >> str;
		stack<char> s;
		for (int i = 0; i < str.length(); i++) {
			if (s.empty() || s.top() != str[i]) {
				s.push(str[i]);
			}
			else {
				s.pop();
			}
		}
		if (s.empty()) ans++;
	}
	cout << ans;
}