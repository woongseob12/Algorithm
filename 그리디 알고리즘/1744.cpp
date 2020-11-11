#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, ans = 0;
	cin >> N;
	vector<int> ary(N);
	for (int i = 0; i < N; i++) {
		cin >> ary[i];
	}
	sort(ary.begin(), ary.end(), greater<int>());

	// 양수
	int start = 0;
	while (start + 1 < N) {
		int res = ary[start] * ary[start + 1];
		if (ary[start + 1] > 0) {
			ans += max(res, ary[start] + ary[start + 1]);
			start += 2;
		}
		else {
			break;
		}
	}
	if (start != N && ary[start] > 0) {
		ans += ary[start];
		start++;
	}

	// 0 & 음수
	int end = N - 1;
	while (end - 1 >= start) {
		int res = ary[end] * ary[end - 1];
		ans += res;
		end -= 2;
	}
	if (end == start) {
		ans += ary[end];
	}
	cout << ans << endl;
}