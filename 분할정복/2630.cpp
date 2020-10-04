#include <iostream>
using namespace std;

int paper[128][128];
int white_n, blue_n;

void sol(int n, int x, int y);
bool blue(int n, int x, int y);
bool white(int n, int x, int y);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	sol(n, 0, 0);
	cout << white_n << endl << blue_n << endl;
}

void sol(int n, int x, int y)
{
	if (blue(n, x, y)) {
		blue_n++;
		return;
	}
	else if (white(n, x, y)) {
		white_n++;
		return;
	}
	else {
		sol(n / 2, x, y);
		sol(n / 2, x + n / 2, y);
		sol(n / 2, x, y + n / 2);
		sol(n / 2, x + n / 2, y + n / 2);
	}
}

bool blue(int n, int x, int y)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (paper[i + x][j + y] == 0) {
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
			if (paper[i + x][j + y] == 1) {
				return false;
			}
		}
	}
	return true;
}