#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> num, ans, trace;
void backtrace(int idx, int n);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	num.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	ans.push_back(num[0]);
	trace.push_back(1);
	for (int i = 1; i < N; i++) {
		if (ans.back() < num[i]) {
			ans.push_back(num[i]);
			trace.push_back(ans.size());
		}
		else {
			vector<int>::iterator iter = lower_bound(ans.begin(), ans.end(), num[i]);
			*iter = num[i];
			trace.push_back(iter - ans.begin() + 1);
		}
	}

	cout << ans.size() << "\n";
	backtrace(N - 1, ans.size());
}

void backtrace(int idx, int len) {
	if (idx == -1)
		return;

	if (trace[idx] == len) {
		backtrace(idx - 1, len - 1);
		cout << num[idx] << " ";
	}
	else {
		backtrace(idx - 1, len);
	}
}
