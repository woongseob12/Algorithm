#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;

	int money[] = { 25, 10, 5, 1 };
	while (tc--) {
		vector<int> cnt(4, 0);
		int give;
		cin >> give;
		for (int i = 0; i < cnt.size(); i++) {
			cnt[i] = give / money[i];
			give %= money[i];
		}

		for (int i = 0; i < cnt.size(); i++) {
			cout << cnt[i] << " ";
 		}
		cout << "\n";
	}
}