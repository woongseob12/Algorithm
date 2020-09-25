#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b);

int main()
{
	int n;
	cin >> n;

	int start, end;
	vector<pair<int, int>> time;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		time.push_back(make_pair(start, end));
	}
	sort(time.begin(), time.end(), cmp);

	int endTime = time[0].second, cnt = 1;
	for (int next = 1; next < n; next++) {
		if (endTime <= time[next].first) {
			endTime = time[next].second;
			cnt++;
		}
	}

	cout << cnt << endl;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}