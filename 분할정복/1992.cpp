#include <iostream>
#include <string>
using namespace std;

int video[64][64];
string ans = "";

bool black(int n, int x, int y);
bool white(int n, int x, int y);
void sol(int n, int x, int y);

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			video[i][j] = temp.at(j) - '0';
		}
	}
	sol(n, 0, 0);
	cout << ans << endl;
}

void sol(int n, int x, int y)
{
	if (black(n, x, y)) {
		ans += "1";
		return;
	}
	else if (white(n, x, y)) {
		ans += "0";
		return;
	}
	else {
		ans += "(";
		sol(n / 2, x, y);
		sol(n / 2, x, y + n / 2);
		sol(n / 2, x + n / 2, y);
		sol(n / 2, x + n / 2, y + n / 2);
		ans += ")";
	}
}

bool black(int n, int x, int y)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (video[i + x][j + y] == 0) {
				return false;
			}
		}
	}
	return true;
}

bool white(int n, int x, int y)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (video[i + x][j + y] == 1) {
				return false;
			}
		}
	}
	return true;
}