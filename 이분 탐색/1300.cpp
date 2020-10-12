#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> k;
	int first = 1, last = k, mid, ans = 0;
	while (first <= last) {
		int cnt = 0;
		mid = (first + last) / 2;
		for (int i = 1; i <= N; i++) {
			cnt += min(mid/ i, N);
		}
		if (cnt < k) {
			first = mid + 1;
		}
		else {
			ans = mid;
			last = mid - 1;
		}
	}
	cout << ans << endl;
}