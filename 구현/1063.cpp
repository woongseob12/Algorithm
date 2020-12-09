#include <iostream>
#include <string>
using namespace std;

void init();

int main()
{
	init();
	string kingPos, stonePos;
	int cnt;
	cin >> kingPos >> stonePos >> cnt;
	int kingPosAry[2], stonePosAry[2];
	kingPosAry[0] = kingPos.at(0) - 'A';
	kingPosAry[1] = kingPos.at(1) - '0';
	stonePosAry[0] = stonePos.at(0) - 'A';
	stonePosAry[1] = stonePos.at(1) - '0';
	while (cnt--) {
		string command;
		cin >> command;
		int kx = kingPosAry[0], ky = kingPosAry[1];

		if (command == "R") {
			kx++;
		}
		else if (command == "L") {
			kx--;
		}
		else if (command == "B") {
			ky--;
		}
		else if (command == "T") {
			ky++;
		}
		else if (command == "RT") {
			kx++;
			ky++;
		}
		else if (command == "LT") {
			kx--;
			ky++;
		}
		else if (command == "RB") {
			kx++;
			ky--;
		}
		else if (command == "LB") {
			kx--;
			ky--;
		}
		if (kx < 0 || kx > 7 || ky < 1 || ky > 8) { continue; }
		if (kx == stonePosAry[0] && ky == stonePosAry[1]) {
			int sx = stonePosAry[0] + kx - kingPosAry[0], sy = stonePosAry[1] + ky - kingPosAry[1];
			if (sx < 0 || sx > 7 || sy < 1 || sy > 8) { continue; }
			stonePosAry[0] += kx - kingPosAry[0];
			stonePosAry[1] += ky - kingPosAry[1];
		}
		kingPosAry[0] = kx;
		kingPosAry[1] = ky;
	}
	char alpha = 'A' + kingPosAry[0];
	cout << alpha << kingPosAry[1] << endl;
	alpha = 'A' + stonePosAry[0];
	cout << alpha << stonePosAry[1] << endl;
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}