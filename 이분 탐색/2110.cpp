#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
int distance(vector<int> home);

int main()
{
	cin >> n >> c;
	vector<int> home(n);
	for (int i = 0; i < n; i++) {
		cin >> home[i];
	}
	sort(home.begin(), home.end());

	cout << distance(home) << endl;
}

int distance(vector<int> home)
{
	int low = home[0], high = home[n - 1], cnt, ans = 0;
	while (low <= high) {
		int mid = (low + high) / 2, start = home[0];
		cnt = 1;
		for (int i = 1; i < n; i++) {
			if (home[i] - start >= mid) {
				start = home[i];
				cnt++;
			}
		}
		if (cnt < c) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
			ans = max(ans, mid);
		}
	}
	return ans;
}