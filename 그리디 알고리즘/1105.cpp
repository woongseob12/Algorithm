#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int L, R;
	cin >> L >> R;
	int diff = R - L;
	string strL = to_string(L), strR = to_string(R);
	int ans = 0, idx = 0;
	if (strL.size() == strR.size()) {
		while (idx < (int)strL.size() && strL[idx] == strR[idx]) {
			if (strL[idx] == '8') {
				ans++;
			}
			idx++;
		}
	}
	cout << ans << endl;
}