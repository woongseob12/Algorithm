#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		int a, b;
		cin >> a >> b;

		// 시간을 줄이는 계산
		a %= 10;
		b = b % 4 ? b % 4 : 4;
		//
		int ans = 1;
		for (; b-- ; ) {
			ans *= a;
			ans %= 10;
			if (ans == 0) {
				ans = 10;
			}
		}
		cout << ans << '\n';
	}
}