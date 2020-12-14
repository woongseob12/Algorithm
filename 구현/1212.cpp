#include <iostream>
#include <string>
using namespace std;

string change(int n);

int main()
{
	string s, ans;
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++) {
		ans += change(s[i] - '0');
	}

	if (s[0] - '0' < 4) {
		if (s == "0") {
			ans = "0";
		}
		else {
			auto it = ans.begin();
			while (*it == '0') {
				ans.erase(it);
			}
		}		
	}
	cout << ans << endl;
}

string change(int n) {
	int a, b, c;
	a = n % 2;
	b = n / 2 % 2;
	c = n / 4;
	string s = to_string(c) + to_string(b) + to_string(a);
	return s;
}