#include <iostream>
#include <string>
#include <vector>
using namespace std;

string book, text;
vector<int> makeTable();
bool kmp();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> book >> text;
	cout << kmp();
}

vector<int> makeTable() {
	int len = text.size();
	vector<int> table(len, 0);
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && text[i] != text[j]) {
			j = table[j - 1];
		}
		if (text[i] == text[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

bool kmp() {
	vector<int> table;
	table = makeTable();
	int b = book.size();
	int t = text.size();
	int j = 0;
	for (int i = 0; i < b; i++) {
		if (book[i] >= '0' && book[i] <= '9') {
			continue;
		}
		while (j > 0 && book[i] != text[j]) {
			j = table[j - 1];
		}
		if (book[i] == text[j]) {
			++j;
			if (j == t) {
				return true;
			}
		}
	}
	return false;
}