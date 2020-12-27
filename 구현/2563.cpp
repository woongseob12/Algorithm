#include <iostream>
using namespace std;

int map[100][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int paper;
	cin >> paper;

	for (int i = 0; i < paper; i++) {
		int x, y;
		cin >> x >> y;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				map[y + i][x + j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
}