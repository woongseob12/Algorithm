#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	string s;
	cin >> s;
	vector<int> n;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] >= 'A' && s[i] <= 'F') {
			n.push_back(s[i] - 'A' + 10);
		}
		else {
			n.push_back(s[i] - '0');
		}
	}
	
	int ans = 0;
	for (int i = 0; i < (int)n.size(); i++) {
		ans += n[i] * (int)pow(16, i);
	}

	cout << ans << endl;
}