#pragma warning(disable : 4996)
#include <cstdio>

int main()
{
	int testCase, i, j, k;
	scanf("%d", &testCase);

	for (i = 0; i < testCase; i++) {
		int num;
		scanf("%d", &num);
		bool prime[10001];
		for (j = 2; j <= 10000; j++) {
			prime[j] = true;
		}
		for (j = 2; j * j <= 10000; j++) {
			if (prime[j]) {
				for (k = j * j; k <= 10000; k += j) {
					prime[k] = false;
				}
			}
		}
		int first, last;
		for (j = 2; j <= 10000; j++) {
			if (prime[j]) {
				if (!prime[num - j]) {
					continue;
				}
				if (j > num - j) {
					break;
				}
				first = j;
				last = num - first;

			}
		}
		printf("%d %d\n", first, last);
	}		
}
