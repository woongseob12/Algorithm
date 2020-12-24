#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> str;
	int len = str.size(), score = 1, ans = 0;
	bool plus = false;
	stack<char> s;

	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			s.push(str[i]);
			score *= 2;
			plus = true;
		}
		else if (str[i] == '[') {
			s.push(str[i]);
			score *= 3;
			plus = true;
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() == '[') {
				ans = 0;
				break;
			}
			else {
				if (plus) {
					ans += score;
					plus = false;
				}
				score /= 2;
				s.pop();
			}
		}
		else {
			if (s.empty() || s.top() == '(') {
				ans = 0;
				break;
			}
			else {
				if (plus) {
					ans += score;
					plus = false;
				}
				score /= 3;
				s.pop();
			}
		}
	}
	if (!s.empty()) {
		ans = 0;
	}
	cout << ans;
}
