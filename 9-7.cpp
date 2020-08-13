#include <iostream>
using namespace std;

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i<testCase; i++){
		int num[15][15];
		int floor, room;
		cin >> floor >> room;
		for (int j = 1; j < 15; j++) {
			num[0][j] = j;
		}
		for (int j = 1; j < 15; j++) {
			num[j][1] = 1;
		}
		for (int j = 1; j < 15; j++) {
			for (int k = 2; k < 15; k++) {
				num[j][k] = num[j - 1][k] + num[j][k - 1];
			}
		}
		cout << num[floor][room] << endl;
	}
}
