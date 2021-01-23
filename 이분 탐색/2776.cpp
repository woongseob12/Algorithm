#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> note1, note2;
int findNum(int n, int low, int high);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		cin >> N;
		note1.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> note1[i];
		}
		sort(note1.begin(), note1.end());

		cin >> M;
		note2.resize(M);
		for (int i = 0; i < M; i++) {
			cin >> note2[i];
		}

		for (int i = 0; i < M; i++) {
			cout << findNum(note2[i], 0, note1.size() - 1) << '\n';
		}
	}
}

int findNum(int n, int low, int high) {
	int mid = (low + high) / 2;
	while (low <= high) {
		mid = (low + high) / 2;
		if (note1[mid] == n) {
			return 1;
		}
		else if (note1[mid] < n) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return 0;
}