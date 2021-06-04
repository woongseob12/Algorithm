#include <iostream>
using namespace std;

int main()
{
	int sugar;
	cin >> sugar;

	int cnt = sugar / 5;
	int* ary = new int[cnt + 1];
	bool able = false;

	for (int i = 0; i <= cnt; i++) {
		ary[i] = (sugar - 5 * i) / 3;
	}
	for (int i = 0; i <= cnt; i++) {
		if (i * 5 + 3 * ary[i] == sugar) {
			able = true;
		}
	}
	if (able == false) {
		cout << -1 << endl;
	}
	else {
		int min = 0;
		for (int i = 0; i <= cnt; i++) {
			if (i * 5 + 3 * ary[i] == sugar) {
				min = i + ary[i];
			}
		}
		cout << min << endl;
	}
}
