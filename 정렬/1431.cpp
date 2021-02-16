#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string s1, string s2) {
	if (s1.size() == s2.size()) {
		int a = 0, b = 0;
		for (int i = 0; i < (int)s1.size(); i++) {
			if (s1[i] >= '0' && s1[i] <= '9') {
				a += s1[i] - '0';
			}
			if (s2[i] >= '0' && s2[i] <= '9') {
				b += s2[i] - '0';
			}
		}
		if (a < b) {
			return true;
		}
		else if (a > b) {
			return false;
		}
		else {
			return s1 < s2;
		}
	}
	return s1.size() < s2.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	  
	int N;
	cin >> N;
	vector<string> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < N; i++) {
		cout <<  v[i] << '\n';
	}
}