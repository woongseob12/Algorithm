#include <iostream>
#include <algorithm>
using namespace std;

int value[501][501];
int sum[501][501];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> value[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			sum[i][j] = value[i][j] + max(sum[i - 1][j - 1], sum[i-1][j]);
		}
	}
	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (max < sum[N][i]) {
			max = sum[N][i];
		}
	}
	cout << max << endl;
}