#include <iostream>
using namespace std;

int main()
{
	char num1[4], num2[4];
	cin >> num1 >> num2;

	char temp;
	temp = num1[0];
	num1[0] = num1[2];
	num1[2] = temp;

	temp = num2[0];
	num2[0] = num2[2];
	num2[2] = temp;

	int n1, n2;
	n1 = atoi(num1);
	n2 = atoi(num2);

	if (n1 > n2) {
		cout << n1;
	}
	else {
		cout << n2;
	}
}
