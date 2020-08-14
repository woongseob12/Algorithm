#pragma warning(disable: 4996)
#include <cstdio>

int main()
{
	int min, max;
	scanf("%d %d", &min, &max);
	bool prime[1000001];

	prime[1] = false;
	for (int i = 2; i <= 1000000 ; i++) {
		prime[i] = true;
	}
	for (int i = 2; i * i <= max; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= max; j += i) {
				prime[j] = false;
			}
		}
	}
	for (int i = min; i <= max; i++) {
		if (prime[i]) {
			printf("%d\n", i);
		}
	}
}
