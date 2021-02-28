#include <iostream>
#include <iomanip>
using namespace std;

int N, W;
int leaf[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> W;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		leaf[a]++;
		leaf[b]++;
	}

	double num = 0;
	for (int i = 2; i <= N; i++) {
		if (leaf[i] == 1) {
			num++;
		}
	}
	cout << fixed << setprecision(10) << (double)W / num << "\n";
}
