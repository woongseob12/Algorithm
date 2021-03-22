#include <iostream>
#include <string>
#include <vector>
using namespace std;

string T, P;
vector<int> idx, table;
void makeTable();
void kmp();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	getline(cin, T);
	getline(cin, P);

	kmp();
	cout << idx.size() << '\n';
	for (int i = 0; i < idx.size(); i++) {
		cout << idx[i] << " ";
	}

}

void makeTable() {
	int pLen = P.size();
	table.resize(pLen, 0);
	int j = 0;
	for (int i = 1; i < pLen; i++) {
		while (j > 0 && P[i] != P[j]) {
			j = table[j - 1];
		}
		if (P[i] == P[j]) {
			table[i] = ++j;
		}
	}
}

void kmp() {
	makeTable();
	int tLen = T.size();
	int pLen = P.size();
	int j = 0;
	for (int i = 0; i < tLen; i++) {
		while (j > 0 && T[i] != P[j]) {
			j = table[j - 1];
		}
		if (T[i] == P[j]) {
			j++;
			if (j == pLen) {
				idx.push_back((i + 1) - pLen + 1);
				j = table[j - 1];
			}
		}
	}
}

