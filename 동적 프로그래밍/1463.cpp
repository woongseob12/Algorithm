#include <iostream>
#include <algorithm>
using namespace std;

int ans[1000001];

int main()
{

	int N;
	cin >> N;

	ans[2] = 1;
	ans[3] = 1;

	for (int i = 4; i <= N; i++) {
		if (i % 3 == 0) {
			ans[i] = min(ans[i - 1] + 1,ans[i / 3] + 1);
		}
		else if (i % 2 == 0) {
			ans[i] = min(ans[i - 1] + 1, ans[i / 2] + 1);
		}
		else {
			ans[i] = ans[i - 1] + 1;
		}
	}
	cout << ans[N] << endl;
}
