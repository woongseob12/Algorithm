#include <iostream>
using namespace std;

int money[10];

int main()
{
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}

	int index = 0;
	while (money[index] < k && index < n) {
		index++;
	}
	index--;

	int cnt = 0;
	for (int i = index; i >= 0; i--) {
		cnt += k / money[i];
		k %= money[i];
	}
	cout << cnt << endl;
} 
