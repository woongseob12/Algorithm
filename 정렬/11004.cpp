#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> ary;
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		ary.push_back(val);
	}
	sort(ary.begin(), ary.end());
	cout << ary[K - 1] << '\n';
}