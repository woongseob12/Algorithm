#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum[10001];
int grape[10001];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> grape[i];
	}

	sum[1] = grape[1];
	sum[2] = grape[1] + grape[2];
	for (int i = 3; i <= n; i++) {
		sum[i] = max(sum[i - 2] + grape[i], sum[i - 3] + grape[i - 1] + grape[i]);
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < sum[i]) {
			max = sum[i];
		}
	}
	cout << max << endl;
}