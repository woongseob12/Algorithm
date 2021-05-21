#include <iostream>
using namespace std;

int arr[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b, num = 1, cnt = 1;
	cin >> a >> b;
	for (int i = 1; i <= b; i++) {
		arr[i] = arr[i - 1] + num;
		cnt--;
		if (cnt == 0) {
			num++;
			cnt = num;
		}
	}
	cout << arr[b] - arr[a - 1];
}