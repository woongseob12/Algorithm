#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	unordered_map<int, int> m;
	string temp;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			temp += s[i];
		}
		else if (s[i] == '}' || s[i] == ',') {
			if (temp != "") {
				int n = stoi(temp);
				m[n]++;
				temp = "";
			}
		}
	}

	priority_queue<pair<int, int>> pq;
	for (auto it = m.begin(); it != m.end(); it++) {
		pq.push({ it->second, it->first });
	}
	while (!pq.empty()) {
		answer.push_back(pq.top().second);
		pq.pop();
	}
	return answer;
}