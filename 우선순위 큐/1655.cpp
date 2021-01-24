#include <queue>
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		if (i % 2 == 1) {
			minHeap.push(val);
		}
		else {
			maxHeap.push(val);
		}

		if (i >=2 && minHeap.top() < maxHeap.top()) {
			int maxTemp = maxHeap.top(), minTemp = minHeap.top();
			maxHeap.pop();
			minHeap.pop();
			maxHeap.push(minTemp);
			minHeap.push(maxTemp);
		}
		if (i % 2 == 1) {
			cout << minHeap.top() << '\n';
		}
		else {
			cout << maxHeap.top() << '\n';
		}
	}
}
