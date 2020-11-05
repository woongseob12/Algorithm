#include <iostream>
using namespace std;

int main()
{
	int money, ans = 0;
	cin >> money;
	money = 1000 - money;
	if (money >= 500) {
		ans += money / 500;
		money %= 500;
	}
	if (money >= 100) {
		ans += money / 100;
		money %= 100;
	}
	if (money >= 50) {
		ans += money / 50;
		money %= 50;
	}
	if (money >= 10) {
		ans += money / 10;
		money %= 10;
	}
	if (money >= 5) {
		ans += money / 5;
		money %= 5;
	}
	if (money >= 1) {
		ans += money / 1;
		money %= 1;
	}
	cout << ans << endl;
}