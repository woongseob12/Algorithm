#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, cnt;
int dx[4] = { 1, 2, 2, 1 };
int dy[4] = { 2, 1, -1, -2 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	if (N >= 3) {	// 움직임에 y는 제약이 없음
		if (M >= 7) {
			cout << M - 2 << endl;
		}
		else if (M >= 4) {
			cout << 4 << endl;
		}
		else {
			cout << M << endl;
		}
	}
	else {		// 2, 3번 방법으로 밖에 움직일 수 없음
		if (N == 1) {
			cout << 1 << endl;
		}
		else {
			if (M >= 7) {
				cout << 4 << endl;
			}
			else {
				if (M >= 5) {
					cout << 3 << endl;
				}
				else if (M >= 3) {
					cout << 2 << endl;
				}
				else {
					cout << 1 << endl;
				}
			}
		}
	}
}