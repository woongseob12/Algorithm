#include <iostream>
#include <vector>
#include <stack>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> A(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	ll ans = 0;
	int val;
	stack<int> s;
	for (int i = 1; i <= n; i++) {
		if (s.empty()) {
			s.push(A[i]);
		}
		else {
			if (s.top() >= A[i]) {
				s.push(A[i]);
			}
			else {
				while (s.top() < A[i]) {
					int val = s.top();
					s.pop();
					if (s.empty() || s.top() > A[i]) {
						ans += A[i] - val;
						break;
					}
					else {
						ans += s.top() - val;
					}
				}
				s.push(A[i]);
			}
		}
	}

	if (!s.empty()) {
		int low = s.top();
		while (s.size() != 1) {
			s.pop();
		}
		int high = s.top();
		ans += high - low;
	}
	
	cout << ans;
}