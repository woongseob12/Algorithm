#include <iostream>
#include <string>
using namespace std;

bool s[21];
void init();

int main()
{
	init();
	int M;
	cin >> M;
	while (M--) {
		string str;
		cin >> str;
		if (str == "add") {
			int val;
			cin >> val;
			s[val] = true;
		}
		else if (str == "remove") {
			int val;
			cin >> val;
			s[val] = false;
		}
		else if (str == "check") {
			int val;
			cin >> val;
			cout << s[val] << '\n';
		}
		else if (str == "toggle") {
			int val;
			cin >> val;
			if (s[val]) {
				s[val] = false;
			}
			else {
				s[val] = true;
			}
		}
		else if (str == "all") {
			for (int i = 1; i <= 20; i++) {
				s[i] = true;
			}
		}
		else if (str == "empty") {
			for (int i = 1; i <= 20; i++) {
				s[i] = false;
			}
		}
	}
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
