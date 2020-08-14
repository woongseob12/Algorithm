#include <iostream>
using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int ary[4];
	ary[0] = x;
	ary[1] = w - x;
	ary[2] = y;
	ary[3] = h - y;
	int min = ary[0];
	for (int i = 1; i < 4; i++) {
		if (min > ary[i]) {
			min = ary[i];
		}
	}
	cout << min << endl;
}
