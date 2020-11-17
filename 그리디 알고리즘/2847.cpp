#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> score(N);
	for (int i = 0; i < N; i++) {
		cin >> score[i];
	}
	int ans = 0;
	for (int i = N - 2; i >= 0; i--) {
		if (score[i] >= score[i + 1]) {
			ans += (score[i] - score[i + 1] + 1);
			score[i] = score[i + 1] - 1;
		}
	}
	cout << ans << endl;
}