#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

int answer;
vector<bool> visit;
vector<int> ans;
vector<string> user, ban;
set<string> id;

bool sameId(string a, string b) {
	if (a.size() != b.size()) {
		return false;
	}
	int len = a.size();
	for (int i = 0; i < len; i++) {
		if (a[i] == '*' || b[i] == '*') continue;
		if (a[i] != b[i]) return false;
	}
	return true;
}

void dfs(int idx) {
	if (idx == ban.size()) {
		vector<int> arr(ans.size());
		for (int i = 0; i < ans.size(); i++) {
			arr[i] = ans[i];
		}
		sort(arr.begin(), arr.end());
		string temp;
		for (int i = 0; i < ans.size(); i++) {
			temp += to_string(arr[i] + 1);
		}
		id.insert(temp);
		return;
	}

	for (int i = 0; i < user.size(); i++) {
		if (!visit[i] && sameId(user[i], ban[idx])) {
			visit[i] = true;
			ans[idx] = i;
			dfs(idx + 1);
			visit[i] = false;
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	user = user_id;
	ban = banned_id;
	visit.resize(user_id.size());
	ans.resize(banned_id.size());
	dfs(0);
	answer = id.size();
	return answer;
}