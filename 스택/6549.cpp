#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define ll long long
using namespace std;

int main() {
	// 입력
	int tc;
	cin >> tc;
	while (tc != 0) {
		vector<int> h(tc);
		for (int i = 0; i < tc; i++) {
			cin >> h[i];
		}
		// 풀이
		ll ans = 0, maxH, maxW;
		stack<int> s;
		for (int i = 0; i < tc; i++) {
			while (!s.empty() && h[s.top()] > h[i]) {
				// 여태까지의 최대 높이, s.top()은 왼쪽 인덱스
				maxH = h[s.top()];
				s.pop();
				// 오른쪽
				maxW = i;
				// 밑변 = 오른쪽 - 왼쪽 - 1;
				if(!s.empty()) maxW = i - s.top() - 1;
				ans = max(ans, maxH * maxW);
			}
			s.push(i);
		}
		while (!s.empty()) {
			maxH = h[s.top()];
			s.pop();
			maxW = tc;
			if (!s.empty()) maxW = tc - s.top() - 1;
			ans = max(ans, maxH * maxW);

		}
		// 출력
		cout << ans << '\n';
		cin >> tc;
	}
}