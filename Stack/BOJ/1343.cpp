#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> st;
void clear();
bool canMake();
string makeLetter(string ans);
void isLetter(string s, int idx);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s, ans = "";
	cin >> s;

	int idx = 0;

	while (idx < s.length()) {
		if (s[idx] == '.') {
			if (!canMake()) return 0;
			ans = makeLetter(ans);
			ans += ".";
			clear();
			idx++;
		}
		else isLetter(s, idx++);
	}

	if (!st.empty()) {
		if (!canMake()) return 0;
		ans = makeLetter(ans);
	}

	cout << ans;
}

void clear() {
	st = stack<char>();
}

bool canMake() {
	if (st.size() % 2 != 0) {
		cout << -1;
		return false;
	}
	return true;
}

void isLetter(string s, int idx) {
	st.push(s[idx]);
}

string makeLetter(string ans) {
	int loop = st.size() / 4;
	while (loop--) {
		ans += "AAAA";
	}
	if (st.size() % 4) {
		ans += "BB";
	}
	return ans;
}