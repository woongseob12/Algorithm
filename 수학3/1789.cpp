#include <iostream>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll S, N = 1;
	cin >> S;
	while ((N + 1) * N / 2 <= S) {
		N++;
	}
	cout << N - 1 << endl;
}