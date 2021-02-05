#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, greater<>> start, end;
	int N; 
	cin >> N;
	for (int i = 0; i < N; i++) {
		int em, xm;
		cin >> em >> xm;
		start.push(em);
		end.push(xm);
	}
	int num = 0, lastMax = 0, startT, endT;
	bool flag;
	while (!end.empty()) {
		if (!start.empty()) {
			if (start.top() < end.top()) {
				if (++num > lastMax) {
					flag = true;
					lastMax = num;
					startT = start.top();
				}
				start.pop();
			}
			else if (start.top() == end.top()) {
				start.pop();
				end.pop();
			}
			else {
				if (lastMax == num-- && flag) {
					flag = false;
					endT = end.top();
				}
				end.pop();
			}
		}
		else {
			if (lastMax == num-- && flag) {
				flag = false;
				endT = end.top();
			}
			end.pop();
		}
	}
	cout << lastMax << '\n' << startT << " " << endT;
}