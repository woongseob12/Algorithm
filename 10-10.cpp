#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double distance;
		distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << endl;
		}
		else {
			if (r1 + r2 > distance && fabs(r1 - r2) < distance) {
				cout << 2 << endl;
			}
			else if (r1 + r2 == distance || fabs(r1 - r2) == distance) {
				cout << 1 << endl;
			}
			else if (r1 + r2 < distance || distance < fabs(r1 - r2)) {
				cout << 0 << endl;
			}
		}
	}
}
