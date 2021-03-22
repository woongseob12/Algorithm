#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, ans, way;
vector<int> arr, table;
void makeTable();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	arr.resize(N);
	for (int i = N - 1; i >= 0; i--) {
		cin >> arr[i];
	}

	makeTable();
	if (ans == 0) {
		cout << -1;
	}
	else {
		cout << ans << " " << way;
	}
}

void makeTable() {
	table.resize(N, 0);
	int j = 0;
	for (int i = 1; i < N; i++) {
		while (j > 0 && arr[i] != arr[j]) {
			j = table[j - 1];
		}
		if (arr[i] == arr[j]) {
			table[i] = ++j;
		}
	}

	for (int i = 0; i < N; i++) {
		if (ans < table[i]) {
			ans = table[i];
			way = 1;
		}
		else if (ans == table[i]) {
			way++;
		}
	}
}