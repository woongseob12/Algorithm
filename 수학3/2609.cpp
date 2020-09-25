#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int small = min(a, b);
	vector<int> divisor;
	for (int i = 1; i <= small; i++) {
		if (small % i == 0) {
			divisor.push_back(i);
		}
	}
	int big = max(a, b), GCD, LCM;
	for (int i = 0; i < (int)divisor.size(); i++) {
		if (big % divisor[i] == 0) {
			GCD = divisor[i];
		}
	}
	LCM = big / GCD * small;

	cout << GCD << endl << LCM << endl;
}