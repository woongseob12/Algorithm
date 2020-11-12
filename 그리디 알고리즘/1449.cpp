#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, L;
	cin >> N >> L;
	vector<int> pipe(N);
	for (int i = 0; i < N; i++) {
		cin >> pipe[i];
	}
	sort(pipe.begin(), pipe.end());
	int cnt = 1, len = pipe[0] + L;
	for (int i = 1; i < N; i++) {
		if (len > pipe[i]) {
			continue;
		}
		else {
			len = pipe[i] + L;
			cnt++;
		}
	}
	cout << cnt << endl;
}
