#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		int N;
		cin >> N;
		vector<pair<int, int>> score(N);
		for (int i = 0; i < N; i++) {
			cin >> score[i].first >> score[i].second;
		}
		sort(score.begin(), score.end());
		int ans = 1, interview = score[0].second;

		for (int i = 1; i < N; i++) {
			if (score[i].second < interview) {
				ans++;
				interview = score[i].second;
			}
		}
		cout << ans << '\n';
	}
}
