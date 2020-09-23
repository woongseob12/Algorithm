#include <iostream>
using namespace std;

int DP[101][10];

int main()
{
	int N;
	cin >> N;
	
	for (int i = 0; i < 10; i++) {
		DP[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				DP[i][0] = DP[i - 1][1];
			}
			else if (j == 9) {
				DP[i][9] = DP[i - 1][8];
			}
			else {
				DP[i][j] = (DP[i - 1][j - 1] + DP[i-1][j + 1]) % 1000000000;
			}
		}
	}
	int sum = 0;
	for (int i = 1; i < 10; i++) {
		sum += DP[N][i] % 1000000000;
	}
	cout << sum << endl;
}