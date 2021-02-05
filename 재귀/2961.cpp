#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, ans = 987654321, n;
pair<int, int> food[10];
priority_queue<int, vector<int>, greater<>> pq;
void sel(int cnt, int sour, int bitter);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> food[i].first >> food[i].second;
	}
	sel(0, 1, 0);
	cout << pq.top();
}

void sel(int cnt, int sour, int bitter) {
	if (cnt == N) {
		if (n != 0) {
			pq.push(abs(sour - bitter));
		}
		return;
	}
	n++;
	sel(cnt + 1, sour * food[cnt].first, bitter + food[cnt].second);
	n--;
	sel(cnt + 1, sour * 1, bitter + 0);
}