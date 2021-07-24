#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int TC, N, M, ans;
vector<pair<int, int>> student;
vector<bool> book;
void init();
void input();
void solve();

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	init();
	solve();
}

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> TC;
}

void input() {
	cin >> N >> M;
	student.clear();
	student.resize(M);
	book.clear();
	book.resize(N + 1);
	ans = 0;
	for (int i = 0; i < M; i++) {
		cin >> student[i].first >> student[i].second;
	}
}

void solve() {
	while (TC--) {
		input();
		sort(student.begin(), student.end(), cmp);
		for (int i = 0; i < M; i++) {
			for (int j = student[i].first; j <= student[i].second; j++) {
				if (!book[j]) {
					book[j] = true;
					ans++;
					break;
				}
			}
		}
		cout << ans << "\n";
	}
}