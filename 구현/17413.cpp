#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	getline(cin, s);
	queue<char> q;
	stack<char> st;
	string ret;
	bool paren = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '<') {
			while (!st.empty()) {
				ret.push_back(st.top());
				st.pop();
			}
			paren = true;
			q.push(s[i]);
		}
		else if (s[i] == '>') {
			paren = false;
			q.push(s[i]);
			while (!q.empty()) {
				ret.push_back(q.front());
				q.pop();
			}
		}
		else if (s[i] == ' ') {
			if (paren) { q.push(s[i]); }
			else {
				while (!st.empty()) {
					ret.push_back(st.top());
					st.pop();
				}
				ret.push_back(s[i]);
			}
		}
		else {
			if (paren) q.push(s[i]);
			else st.push(s[i]);
		}
	}
	while (!st.empty()) {
		ret.push_back(st.top());
		st.pop();
	}
	cout << ret;
}