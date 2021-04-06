#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string msg;
vector<int> solution(string msg);

int main() {
	//input();
	msg = "KAKAO";
	//msg = "TOBEORNOTTOBEORTOBEORNOT";
	//msg = "ABABABABABABABAB";
	vector<int> answer = solution(msg);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;
}

void input() {

}

vector<int> solution(string msg) {
	vector<int> answer;
	unordered_map<string, int> m;
	int idx;
	for (idx = 1; idx <= 26; idx++) {
		char alpha = 'A' + (idx - 1);
		string key;
		key += alpha;
		m.insert({ key, idx });
	}

	for (int i = 0; i < msg.length();) {
		string ans;
		ans += msg[i];
		int j = i;
		if (i == msg.length() - 1) {
			answer.push_back(m[ans]);
			break;
		}
		bool flag = false;
		while (j < msg.length()) {
			if (m.find(ans) == m.end()) {
				m[ans] = idx++;
				ans.erase(ans.length() - 1, 1);
				answer.push_back(m[ans]);
				i = j;
				break;
			}
			else {
				ans += msg[++j];
			}

			if (j == msg.length()) {
				/*cout << ans << "ÀÇ °ª: " << m[ans] << endl;
				cout << m["ABAB"] << endl;*/
				ans.erase(ans.length() - 1, 1);
				answer.push_back(m[ans]);
				flag = true;
				break;
			}
			
		}
		if (flag) break;
	}
	return answer;
}