#pragma warning (disable : 4996)
#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int mod = 2;
	while (n> 1) {
		if (n % mod == 0) {
			printf("%d\n", mod);
			n /= mod;
			mod = 2;
		}
		else {
			mod++;
		}
	}
}