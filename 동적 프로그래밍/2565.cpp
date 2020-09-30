#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b);

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> pole;
	vector<int> dp(n, 1);
	vector<int> num;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		pole.push_back(make_pair(start, end));
	}
	sort(pole.begin(), pole.end(), cmp);

	for (int i = 0; i < n; i++) {
		num.push_back(pole[i].second);
	}

	for (int i = 1; i < n; i++) {	
		for (int j = 1; j < i; j++) {
			if (num[j] < num[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int res = 0;;
	for (int i = 0; i < n; i++) {
		res = max(res, dp[i]);
	}
	cout << n - res << endl;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;

}
