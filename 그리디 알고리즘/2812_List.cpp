#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	string s;
	cin >> s;
	list<char> word;
	for (int i = 0; i < (int)s.size(); i++) {
		word.push_back(s.at(i));
	}

	int cnt = 0;
	list<char>::iterator curr, next;
	for (curr = word.begin(); curr != word.end();) {
		next = curr;
		next++;
		if (next == word.end()) {
			break;
		}
		if (*curr >= *next) {
			curr++;
		}
		else {
			curr = word.erase(curr);
			if (curr != word.begin()) {
				--curr;
			}
			if (++cnt == K) {
				break;
			}
		}
	}

	int needToErase = K - cnt;
	for (int i = 0; i < needToErase; i++) {
		word.erase(--word.end());
	}

	for (auto it = word.begin(); it != word.end(); it++) {
		cout << *it;
	}
}

