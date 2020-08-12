#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	int room = 1;
	int ans = 1;
	while (num > ans) {
		ans += room * 6;
		room++;
	}
	cout << room << endl;
}
