#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
char arr[50][50];
void swap(int i, int j, int a, int b);
void row(int r, int c);
void col(int r, int c);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int nx = j + 1;
			if (nx < N) {
				swap(i, j, i, nx);
				row(i, j); row(i, nx);
				col(i, j); col(i, nx);
				swap(i, j, i, nx);
			} 
			int ny = i + 1;
			if (ny < N) {
				swap(i, j, ny, j);
				row(i, j); row(ny, j);
				col(i, j); col(ny, j);
				swap(i, j, ny, j);
			}
		}
	}
	cout << ans << "\n";
}

void swap(int i, int j, int a, int b) {
	char temp = arr[i][j];
	arr[i][j] = arr[a][b];
	arr[a][b] = temp;
}

void row(int r, int c) {
	for (int i = 0; i < N; i++) {
		char word = arr[i][c];
		int len = 1;
		for (int j = i + 1; j < N; j++) {
			if (arr[j][c] == word) { len++; }
			else { break; }
		}
		ans = max(ans, len);
	}
}

void col(int r, int c) {
	for (int i = 0; i < N; i++) {
		char word = arr[r][i];
		int len = 1;
		for (int j = i + 1; j < N; j++) {
			if (arr[r][j] == word) { len++; }
			else { break; }
		}
		ans = max(ans, len);
	}
}