#include <iostream>
#include <string>
#include <deque>
#include <deque>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string str;
	int  M;
	cin >> str >> M;
	deque<char> first, last;
	int N = str.size();
	for (int i = 0; i < N; i++) {
		first.push_back(str[i]);
	}

	while (M--) {
		char command, word;
		cin >> command;
		if (command == 'P') {
			cin >> word;
			first.push_back(word);
		}
		else if (command == 'L') {
			if (!first.empty()) {
				last.push_back(first.back());
				first.pop_back();
			}			
		}
		else if (command == 'D') {
			if (!last.empty()) {
				first.push_back(last.back());
				last.pop_back();
			}
		}
		else {
			if (!first.empty()) {
				first.pop_back();
			}
		}
	}

	while (!last.empty()) {
		first.push_back(last.back());
		last.pop_back();
	}
	string ans;
	while (!first.empty()) {
		cout << first.front();
		first.pop_front();
	}
}