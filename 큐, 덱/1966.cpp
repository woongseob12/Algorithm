#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int testCase;
	cin >> testCase;
	for (int TC = 0; TC < testCase; TC++) {
		int N, M;
		cin >> N >> M;
		queue<pair<int, int>> printer;	// �ε���, �켱����
		priority_queue<int> importance; // �켱����
		for (int i = 0; i < N; i++) {
			int val;
			cin >> val;
			printer.push(make_pair(i, val));
			importance.push(val);
		}

		int cnt = 0;
		while (!printer.empty()) {
			if (printer.front().second == importance.top()) {
				importance.pop();
				cnt++;
				if (printer.front().first == M) {
					cout << cnt << endl;
					break;
				}
				printer.pop();
			}
			else {
				printer.push(printer.front());
				printer.pop();
			}
		}
	}
}
