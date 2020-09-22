#include <iostream>
#include <algorithm>
using namespace std;

int value[301];
int score[301];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> value[i];
	}
	score[1] = value[1];
	score[2] = value[2];

	for (int i = 3; i <= N; i++) {
		score[i] = max(score[i - 2] + value[i], score[i - 3] + value[i - 1] + value[i]);
	}

	cout << score[N] << endl;
}