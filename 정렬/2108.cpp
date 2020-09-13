#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> res;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		sum += temp;
		res.push_back(temp);
	}
	sort(res.begin(), res.end());

	map<int, int> m;
	for (int i = 0; i < n; i++) {
		m[res[i]]++;
	}

	int max = 0;
	for (auto i = m.begin(); i != m.end(); i++) {
		if (max < i->second) {
			max = i->second;
		}
	}
	vector<int> index;
	for (auto i = m.begin(); i != m.end(); i++) {
		if (max == i->second) {
			index.push_back(i->first);
		}
	}
	int most;
	if (index.size() > 1) {
		sort(index.begin(), index.end());
		most = index[1];
	}
	else {
		most = index[0];
	}

	cout << round((double)sum/n) << endl;
	cout << res[n / 2] << endl;
	cout << most << endl;
	cout << res.back() - res.front() << endl;
}