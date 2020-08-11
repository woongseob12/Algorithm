#include <iostream>
using namespace std;

int equid(int n);

int main()
{
	int ary[1001] = { 0, };
	int num;
	cin >> num;

	int check;
	for (int i = 1; i <= num; i++) {
		check = equid(i);
		ary[check] = check;
	}
	int cnt = 0;
	for (int i = 1; i <= num; i++) {
		if (ary[i] != 0) {
			cnt++;
		}
	}
	cout << cnt << endl;
}

int equid(int n)
{
	if (n < 100) {
		return n;
	}
	else if (n < 1000) {
		int ary[3];
		int res = n;
		for (int i = 0; i < 3; i++) {
			ary[i] = res % 10;
			res /= 10;
		}
		if (ary[0] == ary[1] && ary[1] == ary[2]) {
			return n;
		}
		else if (ary[0] - ary[1] == ary[1] - ary[2]) {
			return n;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}
