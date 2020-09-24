#include <iostream>
#include <algorithm>
using namespace std;

int num[1001];
int L[1001];
int R[1001];

int main()
{
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}

	for (int i = 1; i <= n; i++) {
		L[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (num[j] < num[i]) {
				L[i] = max(L[i], L[j] + 1);
			}
		}
	}
	
	for (int i = n; i >= 1; i--) {
		R[i] = 1;
		for (int j = n; j >= i; j--) {
			if (num[j] < num[i]) {
				R[i] = max(R[i], R[j] + 1);
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum = max(sum,L[i] + R[i] - 1);
	}

	cout << sum << endl;
}