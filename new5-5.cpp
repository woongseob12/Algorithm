#include <iostream>
using namespace std;

int main()
{
	int line;
	int cnt;
	cin >> line;
	for (int i = 1; i <= line * 2 - 1; i++) {
		if (i <= line) {
			for (int j = i; j > 1; j--) {
				cout << " ";
			}
			for (int j = i*2 -1; j <= line * 2 - 1; j++) {
				cout << "*";
			}
			for (int j = i; j > 1; j--) {
				cout << " ";
			}
		}
		else {
			cnt = i - line;
			for (int j = i; j < line * 2 - 1; j++) {
				cout << " ";
			}
			for (int j = 0; j < cnt * 2 + 1; j++) {
				cout << "*";
			}
			for (int j = i; j < line * 2 - 1; j++) {
				cout << " ";
			}
		}
		cout << endl;
	}
}
