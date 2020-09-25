#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int GCD(int a, int b);

int main()
{
	int n;
	cin >> n;

	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());

	int m = num[1] - num[0];
	for (int i = 2; i < n; i++) {
		m = GCD(m, num[i] - num[i - 1]);
	}

	vector<int> divisor;
	for (int i = 2; i * i <= m; i++) {
		if (m % i == 0) {
			divisor.push_back(i);
			divisor.push_back(m / i);
		}
	}
	divisor.push_back(m);
	divisor.erase(unique(divisor.begin(), divisor.end()), divisor.end());
	sort(divisor.begin(), divisor.end());

	for (int i = 0; i < (int)divisor.size(); i++) {
		cout << divisor[i] << " ";
	}
	cout << endl;
}

int GCD(int a, int b)
{
	if (a % b == 0) {
		return b;
	}
	else {
		return GCD(b, a % b);
	}
}