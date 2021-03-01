#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	vector<int> student(N);
	cin >> student[0];
	for (int i = 1; i < N; i++) {
		cin >> student[i];
		student[i - 1] = student [i] - student[i - 1];
	}
	sort(student.begin(), student.end());
	int ans = 0;
	for (int i = 0; i < N - K; i++) {
		ans += student[i];
	}
	cout << ans;
}
