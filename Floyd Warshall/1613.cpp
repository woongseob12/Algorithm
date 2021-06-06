#include <iostream>
using namespace std;

int arr[401][401];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k, s;
	
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = -1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (arr[j][i] == arr[i][k] && arr[j][i] != 0) {
					arr[j][k] = arr[j][i];
				}
			}
		}
	}

	cin >> s;

	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;
		cout << arr[a][b] << "\n";
	}
}