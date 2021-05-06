#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int gLen, len = 987654321, kind;
int ans[2];
unordered_map<string, int> m;
bool haveAll();

//1. 보석 종류 셋팅
void setJ(vector<string> gems) {
	for (int i = 0; i < gLen; i++) {
		m[gems[i]] = 0;
	}
	kind = m.size();
	m.clear();
}

// 2. 투포인터 
void where(vector<string> gems) {
	int e = 0, s = 0;
	for (; s < gLen; s++) {
		while (e < gLen && !haveAll()) {
			m[gems[e]]++;
			e++;
		}
		if (haveAll() && e - s < len) {
			len = e - s;
			ans[0] = s + 1;
			ans[1] = e + 1;
		}
		if (m[gems[s]] == 1) m.erase(gems[s]);
		else m[gems[s]]--;
	}
}

// 3. 모든 종류의 보석이 있니?
bool haveAll() {
	if (m.size() == kind) return true;
	return false;
}

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	gLen = gems.size();
	setJ(gems);
	where(gems);
	answer.push_back(ans[0]);
	answer.push_back(ans[1]);
	return answer;
}