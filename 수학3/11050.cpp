#include <iostream>
using namespace std;

int fact(int n);

int main()
{
	int N, K;
	cin >> N >> K;
	cout << fact(N) / (fact(K) * fact(N - K)) << endl;
}

int fact(int n)
{
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= i;
	}
	return ans;
}