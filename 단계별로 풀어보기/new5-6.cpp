#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n * 2; i++) {	// 줄
		if (i % 2 == 1) {				// 홀수 줄
			for (int j = n; j > 0; j--) {
				if (n % 2 == 0) {
					if (j % 2 == 0) {
						cout << "*";
					}
					else {
						cout << " ";
					}
				}
				else {
					if (j % 2 == 1) {
						cout << "*";
					}
					else {
						cout << " ";
					}
				}
			}
		}
		else {							// 짝수 줄
			for (int j = n; j > 0; j--) {
				if (n % 2 == 1) {
					if (j % 2 == 0) {
						cout << "*";
					}
					else {
						cout << " ";
					}
				}
				else {
					if (j % 2 == 1) {
						cout << "*";
					}
					else {
						cout << " ";
					}
				}
			}
		}
		cout << endl;
	}
}
