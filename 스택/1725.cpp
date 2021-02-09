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
		// ������������ ���� �����ذ��鼭 ���������� �ƴ� ���� ���� ��� ���� ���� ũ�⸦ ���� 
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