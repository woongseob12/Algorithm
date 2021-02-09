#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<int> h(N);
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}

	stack<int> s;
	ll height, width, ans = 0;
	for (int i = 0; i < N; i++) {
		// 오름차순으로 값을 저장해가면서 오름차순이 아닌 값이 들어올 경우 높이 별로 크기를 구함 
		while (!s.empty() && h[s.top()] > h[i]) {
			height = h[s.top()];
			s.pop();
			width = i;
			if (!s.empty()) {
				width = i - s.top() - 1;
			}
			ans = max(ans, width * height);
		}
		s.push(i);
	}
	while (!s.empty()) {
		height = h[s.top()];
		s.pop();
		width = N;
		if (!s.empty()) {
			width = N - s.top() - 1;
		}
		ans = max(ans, width * height);
	}
	cout << ans;
}