#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, l, s;
vector<int> a, d;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l;
	a.resize(n);
	d.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	for (int i = 0; i < n; i++) {
		pq.push({ a[i], i });
		s = i - l;
		while (s >= pq.top().second) {
			pq.pop();
		}
		d[i] = pq.top().first;
	}
	for (int i = 0; i < n; i++) {
		cout << d[i] << " ";
	}
}