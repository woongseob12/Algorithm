#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	for (int TC = 0; TC < tc; TC++) {
		vector<char> ans;
		string s;
		cin >> s;
		int index;
		for (index = 0; index < s.size(); index++) {
			if (s.at(index) == '(') {
				ans.push_back(s.at(index));
			}
			else {
				if (ans.empty()) {
					break;
				}
				else {
					ans.pop_back();
				}
			}
		}
		if (index == s.size() && ans.empty()) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	
}