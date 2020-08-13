#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int x, y;
		cin >> x >> y;
		int distance = y - x;
		int calCnt = (int)sqrt(distance);
		int base = calCnt * calCnt;
		int cnt;

		if (distance == base) {
			cnt = calCnt * 2 - 1;
		}
		else if (distance <= base + calCnt) {
			cnt = calCnt * 2;
		}
		else {
			cnt = calCnt * 2 + 1;
		}
		cout << cnt << endl;
	}
}
