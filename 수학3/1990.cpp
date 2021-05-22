#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int a, b;
set<int> s;
bool prime[100000001];
void buildPel();
void isPrime(int num);
bool checkPrime(int num);
bool isPel(int num);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;
	buildPel();
	for (auto it = s.begin(); it != s.end(); it++) {
		if (*it > b) {
			break;
		}
		if (*it >= a && checkPrime(*it)) {
			cout << *it << "\n";
		}
	}
	cout << -1;
}

void buildPel() {
	s.insert(2);
	s.insert(3);
	s.insert(5);
	s.insert(7);
	for (int i = 1; i <= 9999; i++) {
		string temp = to_string(i);
		string rtemp = temp;
		reverse(rtemp.begin(), rtemp.end());
		s.insert(stoi(temp + rtemp));
		for (int j = 0; j <= 9; j++) {
			string mid = to_string(j);
			s.insert(stoi(temp + mid + rtemp));
		}
	}
}

void isPrime(int num) {
	for (int i = 2; i * i <= num; i++) {
		if (!prime[i]) {
			for (int j = i * i; j <= num; j += i) {
				prime[j] = true;
			}
		}
	}
}

bool checkPrime(int num) {
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

bool isPel(int num) {
	string s = to_string(num);
	int len = s.size();
	for (int i = 0; i < len / 2; i++) {
		if (s[i] != s[len - 1 - i]) {
			return false;
		}
	}
	return true;
}