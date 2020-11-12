#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;
int A[51][51];
int B[51][51];
//bool same[51][51];
void input();
bool except();
int sol();
void change(int y, int x);

int main()
{
	input();
	if (except()) {
		return 0;
	}
	cout << sol() << endl;
}

void input()
{
	cin >> N >> M;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			A[i][j] = s.at(j) - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			B[i][j] = s.at(j) - '0';
		}
	}
}

bool except() 
{
	if (N >= 3 && M >= 3) {
		return false;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) {
				cout << -1 << endl;
				return true;
			}
		}
	}
	cout << 0 << endl;
	return true;
}

int sol()
{	
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 변환 연산 가능 여부 판별
			if (i <= N - 3 && j <= M - 3) {
				if (A[i][j] != B[i][j]) {
					change(i, j);
					ans++;
				}
			}
			// 같은지 판별
			if (A[i][j] != B[i][j]) { return -1; }
		}
	}
	return ans;
}

void change(int y, int x) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (A[y + i][x + j] == 1) {
				A[y + i][x + j] = 0;
			}
			else {
				A[y + i][x + j] = 1;
			}
		}
	}
}