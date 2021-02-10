#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<pair<int,int>> sangmin, jisoo;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> s1, j1;

	int A, B, N;
	cin >> A >> B >> N;

	for (int i = 0; i < N; i++) {
		int t, m;
		char c;
		cin >> t >> c >> m;
		if (c == 'B') {
			for (int j = 0; j < m; j++) {
				if (sangmin.empty()) {
					sangmin.push({ t + A * j, t + A * (j + 1) });
				}
				else {
					if (sangmin.top().second > t + A * j) {
						sangmin.push({ sangmin.top().second, sangmin.top().second + A});
					}
					else {
						sangmin.push({ t + A * j, t + A * (j + 1) });
					}
				}
			}
		}
		else {
			for (int j = 0; j < m; j++) {
				if (jisoo.empty()) {
					jisoo.push({ t + B * j , t + B * (j + 1) });
				}
				else {
					if (jisoo.top().second > t + B * j) {
						jisoo.push({ jisoo.top().second , jisoo.top().second + B});
					}
					else {
						jisoo.push({ t + B * j, t + B * (j + 1) });
					}
				}
			}
		}
	}

	while (!sangmin.empty()) {
		s1.push(sangmin.top());
		sangmin.pop();
	}

	while (!jisoo.empty()) {
		j1.push(jisoo.top());
		jisoo.pop();
	}

	int idx = 1;
	vector<int> s, j;
	while (!s1.empty() && !j1.empty()) {
		if (s1.top().first <= j1.top().first) {
			s.push_back(idx++);
			s1.pop();
		}
		else if (s1.top().first > j1.top().first){
			j.push_back(idx++);
			j1.pop();
		}
	}

	while (!s1.empty()) {
		s.push_back(idx++);
		s1.pop();
	}
	while (!j1.empty()) {
		j.push_back(idx++);
		j1.pop();
	}

	cout << s.size() << '\n';
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << "\n" << j.size() << '\n';
	for (int i = 0; i < j.size(); i++) {
		cout << j[i] << " ";
	}
}
