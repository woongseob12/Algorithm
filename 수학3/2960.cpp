#include <iostream>
using namespace std;

int N, K, cnt;
bool num[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 2; i <= N; i++) {
		if (!num[i]) { 
			for (int j = i; j <= N; j += i) {
				if (num[j]) { continue; }
				num[j] = true;
				cnt++;
				if (cnt == K) {
					cout << j << endl;
					break;
				}
			}
		}
	}
}