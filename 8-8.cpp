#include <iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int num[8] = { 0, };

	for (int i = 0; i < str.length(); i++) {
		if (str[i] <= 67) {
			num[0]++;
		}
		else if (str[i] <= 70) {
			num[1]++;
		}
		else if (str[i] <= 73) {
			num[2]++;
		}
		else if (str[i] <= 76) {
			num[3]++;
		}
		else if (str[i] <= 79) {
			num[4]++;
		}
		else if (str[i] <= 83) {
			num[5]++;
		}
		else if (str[i] <= 86) {
			num[6]++;
		}
		else {
			num[7]++;
		}
	}
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		sum += num[i] * (i + 3);
	}
	cout << sum << endl;
}
