#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int V, E;
int city[401][401];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			city[i][j] = INF;
		}
	}

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		city[a][b] = c;
	}
	
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
				city[j][k] = min(city[j][k], city[j][i] + city[i][k]);
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= V; i++) {
		ans = min(ans, city[i][i]);
	}
	if (ans == INF) ans = -1;
	cout << ans;
}