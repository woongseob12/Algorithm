#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b);

int main()
{
	int n;
	cin >> n;
	vector<int> circle(n);
	for (int i = 0; i < n; i++) {
		cin >> circle[i];
		circle[i] *= 2;
	}

	for (int i = 1; i < n; i++) {
		cout << circle[0] / gcd(circle[0], circle[i]) << "/" << circle[i] / gcd(circle[0], circle[i]) << endl;
	}
}

int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}