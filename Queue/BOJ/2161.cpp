#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	bool flag = false;
	while (!q.empty()) {
		if (!flag) {
			cout << q.front() << " ";
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
		flag = !flag;
	}
}