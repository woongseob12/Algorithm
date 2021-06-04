#include <iostream>
using namespace std;

int d(int n);
int main()
{
	int ary[10001] = { 0, };
	int selfNum;
	for (int i = 1; i <= 10000; i++) {
		selfNum = d(i);
		if (selfNum <= 10000) {
			ary[selfNum] = 1;
		}
	}
	for (int i = 1; i <= 10000; i++) {
		if (ary[i] == 0) {
			cout << i << endl;
		}
	}
}

int d(int n)
{
	int result = n;
	while (n != 0) {
		result += n % 10;
		n /= 10;
	}
	return result;
} 
