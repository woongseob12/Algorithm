#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;
int cnt;

void left();
void right();
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	deque<int> extraction;
	for (int i = 0; i < m; i++) {
		int val;
		cin >> val;
		extraction.push_back(val);
	}
	while (!extraction.empty()) {
		if (extraction.front() == dq.front()) {
			extraction.pop_front();
			dq.pop_front();
		}
		else {
			int idx, dqSize = dq.size();
			for (idx = 0; idx < dqSize; idx++) {
				if (dq[idx] == extraction.front()) {
					break;
				}
			}

			if (idx <= dqSize - idx) {
				left();
			}
			else {
				right();
			}
		}
	}
	cout << cnt << endl;
}

void left()
{
	dq.push_back(dq.front());
	dq.pop_front();
	cnt++;
}

void right()
{
	dq.push_front(dq.back());
	dq.pop_back();
	cnt++;
}