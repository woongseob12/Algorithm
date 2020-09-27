#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	getline(cin,s);
	vector<char> ans;
	while (s != ".") {
		ans.clear();
		int i;
		for (i = 0; i < s.size(); i++) {
			if (s.at(i) == '[' || s.at(i) == '(') {
				ans.push_back(s.at(i));
			}
			else if (s.at(i) == ']') {
				if (ans.empty() || ans.back() != '[') {
					break;
				}
				ans.pop_back();
			}
			else if (s.at(i) == ')') {
				if (ans.empty() || ans.back() != '(') {
					break;
				}
				ans.pop_back();
			}
		}
		if (i == s.size() && ans.empty()) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
		getline(cin,s);
	}
}