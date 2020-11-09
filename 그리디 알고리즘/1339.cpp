#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
bool valid[10];
int c[26];

int main()
{
	int N;
	cin >> N;
	vector<string> word(N);
	map<char, int> alpha;
	for (int i = 0; i < N; i++) {
		cin >> word[i];
		for (int j = 0; j < (int)word[i].length(); j++) {
			c[word[i][j] - 'A'] += pow(10, word[i].length() - j - 1);
		}
	}
	priority_queue<pair<int,int>> pq;
	for (int i = 0; i < 26; i++) {
		if (c[i] != 0) {
			pq.push(make_pair(c[i], i));
		}
	}
	// 알파벳 숫자 변환 참고용 map 생성
	for (int i = 'A'; i <= 'Z'; i++) {
		alpha[i] = 0;
	}

	// 값 넣기
	int start = 9;
	while (!pq.empty()) {
		alpha[(char)(pq.top().second + 'A')] = start;
		pq.pop();
		start--;
	}

	// 변환 알고리즘
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		for (int j = 0; j < (int)word[i].length(); j++) {
			temp += alpha[word[i].at(j)] * pow(10, word[i].length() - j - 1);
		}
		ans += temp;
	}
	cout << ans << endl;
}