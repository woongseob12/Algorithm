#include <iostream>
#define MAX 9
using namespace std;

int arr[MAX], sum = 0;
bool valid[MAX], visit[MAX];
int liar[2];
void sol(int cnt, int s);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < MAX; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sol(0, 0);
	for (int i = 0; i < MAX; i++) {
		if (!valid[i]) {
			cout << arr[i] << "\n";
		}
	}
}

void sol(int cnt, int s) {
	if (cnt == 2) {
		if (sum - s == 100) {
			valid[liar[0]] = true;
			valid[liar[1]] = true;
		}
		return;
	}
	for (int i = 0; i < MAX; i++) {
		if (!visit[i]) {
			visit[i] = true;
			liar[cnt] = i;
			sol(cnt + 1, s + arr[i]);
			visit[i] = false;
		}
	}
}