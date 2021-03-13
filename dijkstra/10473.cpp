#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>
#include <algorithm>
#define MAX 100 + 2
#define INF 987654321
using namespace std;

int n;
vector<pair<double, double>> pos;
vector<pair<int, double>> graph[MAX];
double d[MAX];
void dijk(int start);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int i = 0; i < 2; i++) {
		double x, y;
		cin >> x >> y;
		pos.push_back({ x, y });
	}

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		pos.push_back({ x, y });
	}

	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			if (i == j) { continue; }
			double dist = sqrt(pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2));
			if (i == 0 || j == 0) {
				graph[i].push_back({ j, dist / 5 });
			}
			else {
				double sec;
				if (dist > 50) {
					sec = 2 + (dist - 50) / 5;
				}
				else {
					sec = min(2.0 + (50 - dist)/ 5 , dist / 5);
				}
				graph[i].push_back({ j, sec });
			}
		}
	}
	dijk(0);
}

void dijk(int start) {
	for (int i = 0; i < n + 2; i++) {
		d[i] = INF;
	}
	d[start] = 0;
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
	pq.push({ d[start], start });
	while (!pq.empty()) {
		double cost = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (cost > d[curr]) { continue; }
		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i].first;
			cost = graph[curr][i].second;
			if (d[next] > d[curr] + cost) {
				d[next] = d[curr] + cost;
				pq.push({ d[next], next });
			}
		}
	}
	cout << fixed << setprecision(6) << d[1] << '\n';
}