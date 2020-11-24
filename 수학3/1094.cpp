#include <iostream>
using namespace std;

int main()
{
	int X, cnt = 0;
	int bitMask = 1;
	cin >> X;
	for (int i = 0; i <= 6; i++) {
		if (bitMask & X) {
			cnt++;
		}
		bitMask <<= 1;
	}
	cout << cnt << endl;
}