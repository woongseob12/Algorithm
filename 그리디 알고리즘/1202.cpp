#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) { return a.first > b.first; }
	return a.second > b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> J(N);
	for (int i = 0; i < N; i++) {
		cin >> J[i].first >> J[i].second;
	}
	sort(J.begin(), J.end(), cmp);

	multiset<int> bag;
	for (int i = 0; i < K; i++) {
		int val;
		cin >> val;
		bag.insert(val);
	}
	
	long long ans = 0;
	for (auto iter = J.begin(); iter != J.end(); iter++) {
		auto it_bag = bag.lower_bound(iter->first);
		if (it_bag != bag.end()) {
			ans += iter->second;
			bag.erase(it_bag);
		}
	}
	cout << ans << endl;
}