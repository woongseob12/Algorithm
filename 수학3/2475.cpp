#include <iostream>
using namespace std;

int main()
{
	int num[5];
	for (int i = 0; i < 5; i++) {
		cin >> num[i];
	}
	
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		ans += num[i] * num[i];
	}
	ans %= 10;
	cout << ans << endl;
}