#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, C, M, ans, remain;

typedef struct Info {
	int from;
	int to;
	int w;
}Info;

bool cmp(const Info& o1, const Info& o2) {
	if (o1.to == o2.to) {
		return o1.from < o2.from;
	}
	return o1.to < o2.to;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> C >> M;
	vector<Info> truck;
	for (int i = 0; i < M; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		truck.push_back({ from, to, weight });
	}
	sort(truck.begin(), truck.end(), cmp);

	vector<int> storage(N + 1);
	for (int i = 0; i < M; i++) {
		int box = 0;
		for (int j = truck[i].from; j < truck[i].to; j++) {
			box = max(box, storage[j]);
		}

		int load = min(C - box, truck[i].w);
		ans += load;
		for (int j = truck[i].from; j < truck[i].to; j++) {
			storage[j] += load;
		}
	}
	cout << ans << '\n';
}