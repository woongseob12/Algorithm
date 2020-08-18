#pragma warning(disable : 4996)
#include <cstdio>
#include <cmath>
using namespace std;

void hanoiFunc(int hanoiNum, int start, int pass, int finish);

int main()
{
	int hanoi;
	scanf("%d", &hanoi);
	int cnt = pow(2, hanoi) - 1;
	printf("%d\n", cnt);
	hanoiFunc(hanoi,1,2,3);
	return 0;
}

void hanoiFunc(int hanoiNum, int start, int pass, int finish)
{
	if (hanoiNum == 1) {
		printf("%d %d\n", start, finish);
		return;
	}
	else {
		hanoiFunc(hanoiNum - 1, start, finish, pass);
		printf("%d %d\n", start, finish);
		hanoiFunc(hanoiNum - 1, pass, start, finish);
	}
}
