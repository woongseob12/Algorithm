#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	cin >> N;
	vector<int> rope(N);
	for (int i = 0; i < N; i++) {
		cin >> rope[i];
	}
	sort(rope.begin(), rope.end(), greater<int>());
	int ans = 0, temp = 0, sum = 0;
	for (int i = 0; i < N; i++) {;
		ans = max(ans, rope[i] * (i + 1));
	}
	cout << ans << endl;
}