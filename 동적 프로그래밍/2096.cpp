#include <iostream>
#include <algorithm>
using namespace std;

int game[100000][3];
int dp_MAX[3];
int dp_MIN[3];

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> game[i][0] >> game[i][1] >> game[i][2];
	}

	dp_MAX[0] = dp_MIN[0] = game[0][0];
	dp_MAX[1] = dp_MIN[1] = game[0][1];
	dp_MAX[2] = dp_MIN[2] = game[0][2];

	for (int i = 1; i < N; i++) {
		int temp[3] = { dp_MAX[0], dp_MAX[1], dp_MAX[2] };
		dp_MAX[0] = max(temp[0], temp[1]) + game[i][0];
		dp_MAX[1] = max(temp[0], max(temp[1], temp[2])) + game[i][1];
		dp_MAX[2] = max(temp[1], temp[2]) + game[i][2];
		// ÃÖ¼Ò
		temp[0] = dp_MIN[0];
		temp[1] = dp_MIN[1];
		temp[2] = dp_MIN[2];
		dp_MIN[0] = min(temp[0], temp[1]) + game[i][0];
		dp_MIN[1] = min(temp[0], min(temp[1], temp[2])) + game[i][1];
		dp_MIN[2] = min(temp[1], temp[2]) + game[i][2];
	}
	cout << max(dp_MAX[0], max(dp_MAX[1], dp_MAX[2])) << " " << min(dp_MIN[0], min(dp_MIN[1], dp_MIN[2])) << endl;
}