#include <iostream>
#include <vector>
using namespace std;

long long fibo[91];

int main()
{
	int N;
	cin >> N;
	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= N; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[N] << endl;
}