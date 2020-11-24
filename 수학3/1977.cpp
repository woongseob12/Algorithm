#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	sqrt(M) > (int)sqrt(M) ? M = (int)sqrt(M) + 1: M = (int)sqrt(M);
	N = (int)sqrt(N);
	int sum = 0, min;
	for (int i = M; i <= N; i++) {
		sum += (i * i);
	}
	if (sum == 0) {
		cout << -1 << endl;
	}
	else {
		cout << sum << '\n' << M * M << endl;
	}
}