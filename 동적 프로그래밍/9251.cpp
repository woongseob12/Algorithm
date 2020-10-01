#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int s1_size, s2_size;
	s1_size = s1.size();
	s2_size = s2.size();
	int i, j;
	for (i = 0; i < s1_size; i++) {
		for (j = 0; j < s2_size; j++) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
			}
		}
	}
	cout << dp[i][j] << endl;
}
