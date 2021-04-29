#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, h;
stack<pair<int,int>> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	vector<int> ans(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> h;
		
		if (!s.empty()) {
			if (s.top().first >= h) {
				ans[i] = s.top().second;
			}
			else {
				while (!s.empty() && s.top().first < h) {
					s.pop();
				}
				if (s.empty()) { ans[i] = 0; }
				else { ans[i] = s.top().second; }
			}
		}
		else {
			ans[i] = 0;
		}
		s.push({ h, i });
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}
} 