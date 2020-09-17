#include <iostream>
using namespace std;

const int max = 9;
int sudoku[max][max];
bool row[max][max + 1];
bool col[max][max + 1];
bool rec[max][max + 1];

void dfs(int n);

int main()
{
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] != 0) {
				row[i][sudoku[i][j]] = true;
				col[j][sudoku[i][j]] = true;
				rec[(i / 3) * 3 + (j / 3)][sudoku[i][j]] = true;
			}
		}
	}
	dfs(0);
}

void dfs(int cnt) 
{
	if (cnt == 81) {
		for (int i = 0; i < max; i++) {
			for (int j = 0; j < max; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
	int x = cnt / 9, y = cnt % 9;
	if (sudoku[x][y] != 0) {
		dfs(cnt + 1);
	}
	else {
		for (int i = 1; i <= max; i++) {
			if (!row[x][i] && !col[y][i] && !rec[(x / 3) * 3 + (y / 3)][i]) {
				sudoku[x][y] = i;
				row[x][i] = true;
				col[y][i] = true;
				rec[(x / 3) * 3 + (y / 3)][i] = true;
				dfs(cnt + 1);
				sudoku[x][y] = 0;
				row[x][i] = false;
				col[y][i] = false;
				rec[(x / 3) * 3 + (y / 3)][i] = false;
			}
		}
	}
}