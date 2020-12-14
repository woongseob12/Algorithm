#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define CHICKEN_MAX 13
#define INF 1000000000
using namespace std;

int N, M, ans = INF;
int map[50][50];
bool sel[CHICKEN_MAX];
vector<pair<int,int>> house, chicken, valid;
int calDist(int x1, int y1, int x2, int y2);
void sol();
void comb(int idx, int cnt);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	comb(0, 0);
	cout << ans << '\n';
}

int calDist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

void sol() {
	int totDist = 0;
	for (int i = 0; i < (int)house.size(); i++) {
		int dist = INF;
		for (int j = 0; j < (int)valid.size(); j++) {
			dist = min(dist, calDist(house[i].first, house[i].second, valid[j].first, valid[j].second));
		}
		totDist += dist;
	}
	ans = min(ans, totDist);
}

void comb(int idx, int cnt) {
	if (cnt == M) {
		sol();
		return;
	}
	else{
		for (int i = idx; i < (int)chicken.size(); i++) {
			valid.push_back(chicken[i]);
			comb(i + 1, cnt + 1);
			valid.pop_back();
		}
	}
}
