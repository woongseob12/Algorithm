#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	while (s != "0") {
		int mid = s.size() / 2;
		bool palin = true;

		for (int i = 0; i < mid; i++) {
			if (s.at(i) != s.at(s.size() - 1 - i)) {
				palin = false;
				break;
			}
		}
		if (palin) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
		cin >> s;
	}
}