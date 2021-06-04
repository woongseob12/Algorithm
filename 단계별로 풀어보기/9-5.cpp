#include <iostream>
using namespace std;

int main()
{
	int a, b, v;
	cin >> a >> b >> v;

	int day = (v - b) / (a - b);
	if (day * (a-b) < (v - b)) {
		cout << day + 1 << endl;
	}
	else {
		cout << day << endl;
	}
}
