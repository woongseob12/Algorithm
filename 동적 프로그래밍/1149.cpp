#include <iostream>
#include <algorithm>
using namespace std;

int cost[1001][3];
int sum[1001][3];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	for (int i = 1; i <= N; i++) {
		sum[i][0] = cost[i][0] + min(sum[i - 1][1], sum[i - 1][2]);
		sum[i][1] = cost[i][1] + min(sum[i - 1][0], sum[i - 1][2]);
		sum[i][2] = cost[i][2] + min(sum[i - 1][0], sum[i - 1][1]);
	}
	cout << min(sum[N][0], min(sum[N][1], sum[N][2])) << endl;
}