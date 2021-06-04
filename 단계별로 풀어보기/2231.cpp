#include <iostream>
using namespace std;

int main()
{
	int n, res, index;
	cin >> n;
	for (index = 0; index < n; index++) {
		int temp = index;
		res = index;
		
		while (temp != 0) {
			res += temp % 10;
			temp /= 10;
		}
		if (res == n) {
			break;
		}
	}
	if (index == n) {
		index = 0;
	}
	cout << index << endl;
}