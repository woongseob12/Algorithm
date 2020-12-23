#include <iostream>
using namespace std;

void init();

int dr[4] = { 0, 0, 1, 1 };
int dc[4] = { 0, 1, 0, 1 };
int N, r, c, ans;
void dq(int x, int y, int size);

int main()
{
	init();
	cin >> N >> r >> c;
	dq(0, 0, 1 << N);
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void dq(int row, int col, int size)
{
	if (row == r && col == c) {
		cout << ans << '\n';
		return;
	}
	if (r < row + size && c < col + size && r >= row && c >= col) {
		dq(row, col, size / 2);
		dq(row, col + size / 2, size / 2);
		dq(row + size / 2, col, size / 2);
		dq(row + size / 2, col + size / 2, size / 2);
	}
	else {
		ans += size * size;
	}
}