#define MAX 1001
#define MOD 10007
#include <iostream>
using namespace std;

int dp[MAX][MAX];

int main()
{
	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
            if(i == j || j == 0){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
		}
	}
	cout << dp[N][K] % MOD << endl;
}
