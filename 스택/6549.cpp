#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define ll long long
using namespace std;

int main() {
	// �Է�
	int tc;
	cin >> tc;
	while (tc != 0) {
		vector<int> h(tc);
		for (int i = 0; i < tc; i++) {
			cin >> h[i];
		}
		// Ǯ��
		ll ans = 0, maxH, maxW;
		stack<int> s;
		for (int i = 0; i < tc; i++) {
			while (!s.empty() && h[s.top()] > h[i]) {
				// ���±����� �ִ� ����, s.top()�� ���� �ε���
				maxH = h[s.top()];
				s.pop();
				// ������
				maxW = i;
				// �غ� = ������ - ���� - 1;
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
		// ���
		cout << ans << '\n';
		cin >> tc;
	}
}