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
	if (size == 2) {
		for (int i = 0; i < 4; i++) {
			int nR = row + dr[i], nC = col + dc[i];
			if (nR == r && nC == c) {
				cout << ans << endl;
				return;
			}
			ans++;
		}
		return;
	}
	else {
		// 4분면 나누기
		dq(row, col, size / 2);
		dq(row, col + size / 2, size / 2);
		dq(row + size / 2, col, size / 2);
		dq(row + size / 2, col + size / 2, size / 2);
	}	
}