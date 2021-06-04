#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, cnt = 0;
	cin >> n;
	int ans, num = 666;
	while (cnt != n) {
		string temp = "";
		temp = to_string(num);
		if (temp.find("666") != -1) {
			cnt++;
		}
		num++;
	}
	ans = num - 1;
	cout << ans << endl;
}