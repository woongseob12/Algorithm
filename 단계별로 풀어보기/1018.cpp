#define BOARDSIZE 8
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int same(vector<string> chess, vector<string> board, int x, int y);
int main()
{
	int M, N;
	cin >> M >> N;
	vector<int> res;
	vector<string> black;
	for (int i = 0; i < BOARDSIZE / 2; i++) {
		black.push_back("BWBWBWBW");
		black.push_back("WBWBWBWB");
	}
	vector<string> white;
	for (int i = 0; i < BOARDSIZE / 2; i++) {
		white.push_back("WBWBWBWB");
		white.push_back("BWBWBWBW");
	}
	vector<string> board;
	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;
		board.push_back(temp);
	}

	
	for (int i = 0; i <= M - BOARDSIZE; i++) {
		for (int j = 0; j <= N - BOARDSIZE; j++) {
			res.push_back(same(black, board, i, j));
			res.push_back(same(white, board, i ,j));
		}
	}
	sort(res.begin(), res.end());
	cout << res.front() << endl;
}

int same(vector<string> chess, vector<string> board, int x, int y)
{
	int res = 0;
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			if (chess[i].at(j) != board[i + x].at(j + y)) {
				res++;
			}
		}
	}
	return res;
}