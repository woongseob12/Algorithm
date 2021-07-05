#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[50][50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'Y') {
				arr[i][j] = 1;
				arr[j][i] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (arr[j][i] && arr[i][k]) {
					if (arr[j][k] == 0) {
						arr[j][k] = arr[j][i] + arr[i][k];
					}
					else {
						arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (arr[i][j] <= 2 && arr[i][j] > 0) temp++;
		}
		ans = max(ans, temp);
	}
	cout << ans;
}