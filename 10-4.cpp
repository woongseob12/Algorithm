#pragma warning(disable: 4996)
#include <cstdio>

int main()
{
	int num, i, j;
	scanf("%d", &num);
	while (num != 0) {
		int cnt = 0;
		bool prime[123456 * 2 + 1];
		prime[1] = false;
		for (i = 2; i < 123456 * 2; i++) {
			prime[i] = true;
		}
		for (i = 2; i * i <= 2 * num; i++) {
			if (prime[i]) {
				for (j = i * i; j <= 2 * num; j += i) {
					prime[j] = false;
				}
			}
		}
		for (i = num + 1; i <= 2 * num; i++) {
			if (prime[i]) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
		scanf("%d", &num);
	}
}
