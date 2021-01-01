#include <iostream>
using namespace std;

int N, M, ans;
int num[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < N; i++) {
		int temp = num[i];
		if (temp == M) { 
			ans++;
			continue;
		}
		for (int j = i + 1; j < N; j++) {
			temp += num[j];
			if (temp > M) {
				break;
			}
			else if (temp == M) {
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
}