#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int num[10];
void init();

int main()
{
	init();
	string s;
	cin >> s;
	
	for (int i = 0; i < (int)s.size(); i++) {
		num[s[i] - '0']++;
	}
	int temp = num[6] + num[9];
	if (temp % 2 == 0) {
		num[6] = num[9] = temp / 2;
	}
	else {
		num[6] = num[9] = temp / 2 + 1;
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans = max(ans, num[i]);
	}
	cout << ans << endl;
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}