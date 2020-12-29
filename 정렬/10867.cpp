#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> ary(N);
	for (int i = 0; i < N; i++) {
		cin >> ary[i];
	}
	sort(ary.begin(), ary.end());
	ary.erase(unique(ary.begin(), ary.end()), ary.end());
	for (int i = 0; i < (int)ary.size(); i++) {
		cout << ary[i] << " ";
	}
}