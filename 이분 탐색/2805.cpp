#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sol(vector<int> tree, int m);

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> tree(n);
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}
	sort(tree.begin(), tree.end());

	cout << sol(tree, m) << endl;
}

int sol(vector<int> tree, int m)
{
	int n = tree.size(), ans = 0;
	long long high = tree[n - 1], low = 1;
	while (low <= high) {
		long long mid = (low + high) / 2, total = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] >= mid) {
				total += tree[i] - mid;
			}
		}
		if (total < m) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
			ans = max(ans, (int)mid);
		}
	}
	return ans;
}