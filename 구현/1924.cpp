#include <iostream>
#include <string>
using namespace std;

int main()
{
	int m[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	string week[7] = { "SUN" , "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int x, y;
	cin >> x >> y;
	int day = 0;
	for (int i = x - 2; i >= 0; i--) {
		day += m[i];
	}
	day += y;
	day %= 7;
	cout << week[day] << endl;
}