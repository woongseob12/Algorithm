#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, ans = 0, cnt = 1;
	cin >> N;
	int len = to_string(N).size();
	int start = 1;
	while (start != len) {
		ans += 9 * start * pow(10, start - 1);
		start++;
	}

	ans += (N - pow(10, start - 1) + 1) * len;
	cout << ans << endl;
}
