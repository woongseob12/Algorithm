#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	string ans = str.substr(0, 1);
	for (int i = 1; i < str.size(); i++) {
		if (ans[ans.length()-1] < str[i]) {
			ans = str[i] + ans;
		}
		else {
			ans += str[i];
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}
