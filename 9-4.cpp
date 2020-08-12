#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	int line = 1;
	int ans = 1;
	while (num > ans) {
		line++;
		ans += line;
	}
	ans -= line;

	int lineSumNum = line + 1;
	int startNum = num - ans;
	if (line % 2 == 0) {	
		cout << startNum << "/" << lineSumNum - startNum << endl;
	}
	else {				
		cout << lineSumNum - startNum << "/" << startNum << endl;
	}
}
