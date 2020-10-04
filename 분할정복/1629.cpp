#include <iostream>
using namespace std;

long long a, b, c;
long long divide_conquer(long long a, long long b);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;
	cout << divide_conquer(a,b) << endl;
}

long long divide_conquer(long long a, long long b)
{
	if (b == 1) {
		return a % c;
	}
	long long res;
	if (b % 2 == 0) {	
		res = (divide_conquer(a, b / 2) * divide_conquer(a, b / 2)) % c;
	}
	else {
		res = (divide_conquer(a, b / 2) * divide_conquer(a, b / 2 + 1)) % c;
	}
	return res;
}

