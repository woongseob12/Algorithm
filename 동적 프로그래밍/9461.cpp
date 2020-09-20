#include <iostream>
using namespace std;

int main()
{
	long long p[101];
	int TC;
	cin >> TC;
	p[1] = 1;
	p[2] = 1;
	p[3] = 1;
	p[4] = 2;
	p[5] = 2;
	for (int t = 0; t < TC; t++) {
		int N;
		cin >> N;
		for (int i = 6; i <= N; i++) {
			p[i] = p[i - 5] + p[i - 1];
		}
		cout << p[N] << endl;
	}
}