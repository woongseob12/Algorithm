#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> coin(n);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	sort(coin.begin(), coin.end());
	vector<int> ans(k + 1, -1);
	ans[0] = 0;
	for (int i = coin[0]; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i - coin[j] >= 0 && ans[i - coin[j]] != -1) {
				if (ans[i] != -1) {
					ans[i] = min(ans[i], ans[i - coin[j]] + 1);
				}
				else {
					ans[i] = ans[i - coin[j]] + 1;
				}
			}
		}
	}
	cout << ans[k] << endl;
}