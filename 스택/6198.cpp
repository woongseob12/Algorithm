#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	vector<int> h(N);
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}

	long long ans = 0;
	stack<int> s;
	for (int i = 0; i < N; i++) {
		if (s.empty() || s.top() > h[i]) {
			s.push(h[i]);
		}
		else {
			while (!s.empty()) {
				if (s.top() <= h[i]) {
					s.pop();
				}
				else { break; }
			}
			s.push(h[i]);
		}
		ans += s.size() - 1;
	}
	cout << ans;
}