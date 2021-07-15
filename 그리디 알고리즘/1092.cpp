#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> ship(n);
	for (int i = 0; i < n; i++) {
		cin >> ship[i];
	}
	sort(ship.begin(), ship.end(), greater<>());

	int m;
	cin >> m;
	vector<int> box(m);
	for (int i = 0; i < m; i++) {
		cin >> box[i];
	}
	sort(box.begin(), box.end(), greater<>());
	
	if (box[0] > ship[0]) {
		cout << -1;
	}
	else {
		int ans = 0;
		while (!box.empty()) {
			ans++;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < box.size(); j++) {
					if (ship[i] >= box[j]) {
						box.erase(box.begin() + j);
						break;
					}
				}
			}
		}
		cout << ans;
	}
}