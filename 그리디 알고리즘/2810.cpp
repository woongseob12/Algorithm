#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int couple = 1, ans = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s.at(i) == 'S') {
			ans++;
		}
		else {
			if (couple == 1) {
				ans++;
				couple++;
			}
			else {
				couple = 1;
			}
		}
	}
	ans++;
	// ¹Ý·Ê
	if (ans > n) {
		ans = n;
	}
	cout << ans << endl;
}