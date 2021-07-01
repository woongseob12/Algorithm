#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getPi(string s);
int kmp(string src, string search);
int gcd(int a, int b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	string src, search;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char word;
		cin >> word;
		search += word;
	}
	for (int i = 0; i < n; i++) {
		char word;
		cin >> word;
		src += word;
	}
	
	src += src;
	int m = kmp(src, search);
	if (m >= n) {
		cout << "1/1";
	}
	else {
		int temp = gcd(n, m);
		cout << (m / temp) << "/" << (n / temp);
	}
}

vector<int> getPi(string s) {
	int n = s.size();
	vector<int> pi(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) pi[i] = ++j;
	}
	return pi;
}

int kmp(string src, string search) {
	int n = src.size(), m = search.size();
	vector<int> pi = getPi(search);

	int ans = 0;
	for (int i = 0, j = 0; i < n - 1; i++) {
		while (j > 0 && src[i] != search[j]) j = pi[j - 1];
		if (src[i] == search[j] && ++j == m) {
			ans++;
			j = pi[j - 1];
		}
	}
	return ans;
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
