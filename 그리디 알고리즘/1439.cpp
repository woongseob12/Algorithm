#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int same = s.at(0), idx = 1, cnt = 1;
	while (idx < s.size()) {
		if (same != s.at(idx)) {
			cnt++;
			same = s.at(idx);
		}
		idx++;
	}
	cout << cnt / 2 << endl;
}