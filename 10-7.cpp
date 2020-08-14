#include <iostream>
using namespace std;

int main()
{
	int rectangle[4][2];
	for (int i = 0; i < 3; i++) {
		cin >> rectangle[i][0] >> rectangle[i][1];
	}
	if (rectangle[0][0] == rectangle[1][0]) {
		rectangle[3][0] = rectangle[2][0];
	}
	else if (rectangle[0][0] == rectangle[2][0]) {
		rectangle[3][0] = rectangle[1][0];
	}
	else {
		rectangle[3][0] = rectangle[0][0];
	}

	if (rectangle[0][1] == rectangle[1][1]) {
		rectangle[3][1] = rectangle[2][1];
	}
	else if (rectangle[0][1] == rectangle[2][1]) {
		rectangle[3][1] = rectangle[1][1];
	}
	else {
		rectangle[3][1] = rectangle[0][1];
	}
	cout << rectangle[3][0] << " " << rectangle[3][1] << endl;
}
