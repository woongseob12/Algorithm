#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	int len = s2.length();
	string ans = "";
	for (int i = 0; i < s1.length(); i++) {
		ans += s1[i];
		if (ans[ans.length() - 1] == s2[len - 1]) {
			if (ans.length() >= len && ans.substr(ans.length() - len) == s2) {
				ans.erase(ans.length() - len);
			}
		}
	}
	if (ans.length() == 0) {
		ans = "FRULA";
	}
	cout << ans;
}