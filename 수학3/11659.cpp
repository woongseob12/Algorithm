#include <iostream>
using namespace std;

long long int ary[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	ary[0] = 0;
	for (int i = 1; i <= N; i++) {
		int val;
		cin >> val;
		ary[i] = ary[i - 1] + val;
	}
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		cout << ary[end] - ary[start - 1] << '\n';
	}
}