#include <iostream>
using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int molecular1, molecular2, denominator1, denominator2, ansMolecular, ansDenomiantor;
	cin >> molecular1 >> molecular2 >> denominator1 >> denominator2;
	ansMolecular = molecular1 * (lcm(molecular2, denominator2) / molecular2) + denominator1 * (lcm(molecular2, denominator2) / denominator2);
	ansDenomiantor = lcm(molecular2, denominator2);
	cout << ansMolecular / gcd(ansMolecular, ansDenomiantor) << " " << ansDenomiantor / gcd(ansMolecular, ansDenomiantor) << '\n';
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}