#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<long long> distance(N - 1);
	for (int i = 0; i < N - 1; i++) {
		cin >> distance[i];
	}
	vector<long long> city(N);
	for (int i = 0; i < N; i++) {
		cin >> city[i];
	}

	long long cost = city[0], ans = city[0] * distance[0];
	for (int i = 1; i < N - 1; i++) {
		if (cost > city[i]) {
			cost = city[i];
		}
		ans += distance[i] * cost;
	}
	cout << ans << endl;
}