#include <iostream>
using namespace std;

int main()
{
	int startH, startM, time, endH, endM;
	cin >> startH >> startM >> time;
	endH = startH + time / 60;
	endM = startM + time % 60;
	if (endM >= 60) {
		endM -= 60;
		endH++;
	}
	if (endH >= 24) {
		endH -= 24;
	}
	cout << endH << " " << endM << endl;
}