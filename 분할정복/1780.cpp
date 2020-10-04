#include <iostream>
#include <vector>
using namespace std;

int pos1, neg1, zero;
vector<vector<int>> paper;
void input(int n);
void sol(int n, int x, int y);
bool check_pos1(int n, int x, int y);
bool check_zero(int n, int x, int y);
bool check_neg1(int n, int x, int y);
void output();

int main()
{
	int n;
	cin >> n;

	input(n);
	sol(n, 0 , 0);
	output();
}

void input(int n)
{
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			int val;
			cin >> val;
			temp.push_back(val);
		}
		paper.push_back(temp);
	}
}

void sol(int n, int x, int y)
{
	if (check_pos1(n, x, y)) {
		pos1++;
		return;
	}
	else if (check_zero(n, x, y)) {
		zero++;
		return;
	}
	else if (check_neg1(n, x, y)) {
		neg1++;
		return;
	}
	else {
		sol(n / 3, x, y);
		sol(n / 3, x, y + n / 3);
		sol(n / 3, x, y + n * 2 / 3);
		sol(n / 3, x + n / 3, y);
		sol(n / 3, x + n / 3, y + n / 3);
		sol(n / 3, x + n / 3, y + n * 2 / 3);
		sol(n / 3, x + n * 2 / 3, y);
		sol(n / 3, x + n * 2 / 3, y + n / 3);
		sol(n / 3, x + n * 2 / 3, y + n * 2 / 3);
	}
}

bool check_pos1(int n, int x, int y)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (paper[i + x][j + y] != 1) {
				return false;
			}
		}
	}
	return true;
}

bool check_zero(int n, int x, int y)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (paper[i + x][j + y] != 0) {
				return false;
			}
		}
	}
	return true;
}

bool check_neg1(int n, int x, int y)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (paper[i + x][j + y] != -1) {
				return false;
			}
		}
	}
	return true;
}

void output() {
	cout << neg1 << endl << zero << endl << pos1 << endl;
}