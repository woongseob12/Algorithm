#include <iostream>
using namespace std;

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int floor, room, person;
		cin >> floor >> room >> person;
		int x = 0;
		int y = 0;
		while (person > floor * x) {
			x++;
		}
		y = person - floor * (x - 1);
		if (x < 10) {
			cout << y << "0" << x << endl;
		}
		else {
			cout << y << x << endl;
		}
	}
}
