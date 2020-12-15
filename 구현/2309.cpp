#include <iostream>
#include <algorithm>
using namespace std;

bool liar[9];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int sum = 0;
	int dwarf[9];
	
	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
		sum += dwarf[i];
	}
	sort(dwarf, dwarf + 9);

	int needToDel = sum - 100;
	int first, second;
	for (int i = 0; i < 8; i++) {
		first = dwarf[i];
		for (int j = i + 1; j < 9; j++) {
			second = dwarf[j];
			if (first + second == needToDel) {
				liar[i] = true;
				liar[j] = true;
				break;
			}
		}
		if (first + second == needToDel) {
			break;
		}
	}

	for (int i = 0; i < 9; i++) {
		if (liar[i]) { continue; }
		cout << dwarf[i] << '\n';
	}
}
