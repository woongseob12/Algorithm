#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	return a.length() < b.length();
}

vector<int> solution(string s) {
	vector<int> answer;
	int len = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ',' && s[i - 1] == '}' && s[i + 1] == '{') {
			len++;
		}
	}
	len++;

	vector<string> e;
	string temp;
	for (int i = 1; i < s.length() - 1; i++) {
		if (s[i] == '{') {
			temp = "";
		}
		else if (s[i] == '}') {
			e.push_back(temp);
		}
		else {
			temp += s[i];
		}
	}

	sort(e.begin(), e.end(), cmp);
	vector<bool> visit(100001);
	for (int i = 0; i < e.size(); i++) {
		string num;
		int n;
		for (int j = 0; j < e[i].size(); j++) {
			if (e[i][j] == ',') {
				n = stoi(num);
				if (!visit[n]) {
					visit[n] = true;
					answer.push_back(n);
				}
				num = "";
			}
			else {
				num += e[i][j];
			}
		}
		n = stoi(num);
		if (!visit[n]) {
			visit[n] = true;
			answer.push_back(n);
		}
	}
	return answer;
}