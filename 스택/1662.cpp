#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// 입력
	string str;
	stack<pair<char, int>> s;
	cin >> str;
	int sLen = str.size();
	// 풀이
	for (int i = 0; i < sLen; i++) {
		if (str[i] == ')') {
			int loop = 0;
			while (s.top().first != '(') {
				loop += s.top().second;
				s.pop();
			}
			s.pop();
			s.top().second = loop * (s.top().first - '0');
		}
		else {
			s.push({ str[i], 1 });
		}
	}
	// 출력
	int ans = 0;
	while (!s.empty()) {
		ans += s.top().second;
		s.pop();
	}
	cout << ans;
}