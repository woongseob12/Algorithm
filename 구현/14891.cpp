#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> gear(4);
vector<int> ptr(4, 0);
int left(int topIdx);
int right(int topIdx);
int calIdx(int idx, int n);
void moving(int start, int dir);
int res();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 4; i++) {
		cin >> gear[i];
	}

	int cnt; 
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int num, dir;
		cin >> num >> dir;
		ptr[num - 1] = calIdx(ptr[num - 1], dir);
		moving(num - 1, dir);
	}

	cout << res() << endl;
}

int left(int topIdx) {
	topIdx -= 2;
	if (topIdx < 0) {
		return topIdx + 8;
	}
	return topIdx;
}

int right(int topIdx) {
	topIdx += 2;
	if (topIdx > 7) {
		return topIdx - 8;
	}
	return topIdx;
}

int calIdx(int idx, int n) {
	// 馆矫拌 规氢
	if (n == -1) {
		idx++;
		if (idx > 7) {
			idx -= 8;
		}
	}
	else {
		idx--;
		if (idx < 0) {
			idx += 8;
		}
	}
	return idx;
}

void moving(int start, int dir) {
	int temp = dir * -1;
	// 坷弗率 贸府
	for (int i = start; i < 3; i++) {
		if (gear[i][right(calIdx(ptr[i], temp))] != gear[i + 1][left(ptr[i + 1])]) {
			ptr[i + 1] = calIdx(ptr[i + 1], temp);
			temp *= -1;
		}
		else {
			break;
		}
	}
	// 哭率 贸府
	temp = dir * -1;
	for (int i = start; i > 0; i--) {
		if (gear[i][left(calIdx(ptr[i], temp))] != gear[i - 1][right(ptr[i - 1])]) {
			ptr[i - 1] = calIdx(ptr[i - 1], temp);
			temp *= -1;
		}
		else {
			break;
		}
	}
}

int res() {
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		gear[i][ptr[i]] == '0' ? ans += 0 : ans += (1 << i);
	}
	return ans;
}