#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> h(N);
	int sum = 0, grow = 0;
	for (int i = 0; i < N; i++) {
		cin >> h[i];
		sum += h[i];
		grow += h[i] / 2;
	}

	if (sum % 3 != 0) {
		cout << "NO\n";
	}
	else {
		if(grow >= sum / 3){
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}