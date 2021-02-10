#include <iostream>
using namespace std;

int N, M, R;
int ary[101][101];
int ret[101][101];
void func1();
void func2();
void func3();
void func4();
void func5();
void func6();

int main() {
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ary[i][j];
		}
	}
	for (int i = 0; i < R; i++) {
		int op;
		cin >> op;
		switch (op) {
		case 1:
			func1();
			break;
		case 2:
			func2();
			break;
		case 3:
			func3();
			break;
		case 4:
			func4();
			break;
		case 5:
			func5();
			break;
		case 6:
			func6();
			break;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ary[i][j] << " ";
		}
		cout << '\n';
	}
}

void func1() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ret[N - i - 1][j] = ary[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ary[i][j] = ret[i][j];
		}
	}
}

void func2() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ret[i][M - j - 1] = ary[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ary[i][j] = ret[i][j];
		}
	}
}

void func3() {
	for (int i = 0; i < M; i++) {
		for (int j = N - 1; j >= 0; j--) {
			ret[i][N - j - 1] = ary[j][i];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			ary[i][j] = ret[i][j];
		}
	}
	int temp = N;
	N = M;
	M = temp;
}

void func4() {
	for (int i = M - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			ret[M - i - 1][j] = ary[j][i];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			ary[i][j] = ret[i][j];
		}
	}
	int temp = N;
	N = M;
	M = temp;
}

void func5() {
	int y = N / 2;
	int x = M / 2;
	// 1 -> 2
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			ret[i][j + x] = ary[i][j];
		}
	}
	// 2 -> 3
	for (int i = 0; i < y; i++) {
		for (int j = x; j < M; j++) {
			ret[i + y][j] = ary[i][j];
		}
	}
	// 3 -> 4
	for (int i = y; i < N; i++) {
		for (int j = x; j < M; j++) {
			ret[i][j - x] = ary[i][j];
		}
	}
	// 4 -> 1
	for (int i = y; i < N; i++) {
		for (int j = 0; j < x; j++) {
			ret[i - y][j] = ary[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ary[i][j] = ret[i][j];
		}
	}
}

void func6() {
	int y = N / 2;
	int x = M / 2;
	// 1 -> 4
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			ret[i + y][j] = ary[i][j];
		}
	}
	// 2 -> 1
	for (int i = 0; i < y; i++) {
		for (int j = x; j < M; j++) {
			ret[i][j - x] = ary[i][j];
		}
	}
	// 3 -> 2
	for (int i = y; i < N; i++) {
		for (int j = x; j < M; j++) {
			ret[i - y][j] = ary[i][j];
		}
	}
	// 4 -> 3
	for (int i = y; i < N; i++) {
		for (int j = 0; j < x; j++) {
			ret[i][j + x] = ary[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ary[i][j] = ret[i][j];
		}
	}
}