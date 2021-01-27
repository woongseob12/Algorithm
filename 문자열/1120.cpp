#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int diff = 50;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int temp = 0;
		for (int j = 0; j < a.length(); j++) {
			if (b[i + j] != a[j]) {
				temp++;
			}
		}
		if (diff > temp) {
			diff = temp;
		}
	}
	cout << diff;
}