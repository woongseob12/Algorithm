#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	for (auto iter = s.begin(); iter != s.end();) {
		if (*iter == 'U' || *iter == 'C' || *iter == 'P') {
			iter++;
		}
		else {
			s.erase(iter);
		}
	}
	bool seq[4] = { false, };
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		if (!seq[0] && *iter == 'U') {
			seq[0] = true;
		}
		if (seq[0] && *iter == 'C') {
			seq[1] = true;
		}
		if (seq[1] && *iter == 'P') {
			seq[2] = true;
		}
		if (seq[2] && *iter == 'C') {
			seq[3] = true;
		}
	}
	if (seq[0] && seq[1] && seq[2] && seq[3]) {
		cout << "I love UCPC" << endl;
	}
	else {
		cout << "I hate UCPC" << endl;
	}
}