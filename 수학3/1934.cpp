#include <iostream>
using namespace std;

int gcd(int a, int b);

int main()
{
	int TC;
	cin >> TC;
	while (TC--) {
		int a, b;
		cin >> a >> b;
		cout << a * b / gcd(a, b) << endl;
	}
}

int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}