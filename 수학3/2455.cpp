#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int people = 0, now = 0;

	for (int i = 0; i < 4; i++) {
		int in, out;
		cin >> in >> out;
		people += in;
		people -= out;
		now = max(people, now);
	}

	cout << now << endl;
}