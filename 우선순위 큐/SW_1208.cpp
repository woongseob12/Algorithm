#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int TC = 1; TC <= 10; TC++) {
		int loop;
		cin >> loop;

		priority_queue<int> minHeap;
		priority_queue<int, vector<int>, greater<int>> maxHeap;
		for (int i = 0; i < 100; i++) {
			int val;
			cin >> val;
			minHeap.push(val);
			maxHeap.push(val);
		}

		while (loop-- > 0) {
			int minTemp = minHeap.top();
			minHeap.pop();
			minTemp--;
			minHeap.push(minTemp);
			int maxTemp = maxHeap.top();
			maxHeap.pop();
			maxTemp++;
			maxHeap.push(maxTemp);
		}
		cout << "#" << TC << " " << minHeap.top() - maxHeap.top() << '\n';
	}
}
