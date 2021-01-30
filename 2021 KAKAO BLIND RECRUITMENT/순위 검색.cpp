#include <string>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	map<string, vector<int>> applicant;
	for (int i = 0; i < (int)info.size(); i++) {
		char ch[200];
		strcpy(ch, info[i].c_str());
		char *ptr = strtok(ch, " ");
		int idx = 0;
		string mIdx = "1234";
		while (ptr != NULL) {
			if (idx == 4) {
				applicant[mIdx].push_back(atoi(ptr));
				break;
			}
			mIdx[idx++] = ptr[0];
			ptr = strtok(NULL, " ");
		}
	}

	for (int i = 0; i < query.size(); i++) {
		char ch[300];
		strcpy(ch, query[i].c_str());
		char *ptr = strtok(ch, " ");
		int idx = 0, score, ans = 0;
		string mIdx = "1234";
		while (ptr != NULL) {
			if (idx == 4) {
				score = atoi(ptr);
				break;
			}
			if (strcmp(ptr, "and") == 0) {
				ptr = strtok(NULL, " ");
				continue;
			}
			mIdx[idx++] = ptr[0];
			ptr = strtok(NULL, " ");
		}
		for (auto m = applicant.begin(); m != applicant.end(); m++) {
			if (m->first[0] == mIdx[0] || mIdx[0] == '-') {
				if (m->first[1] == mIdx[1] || mIdx[1] == '-') {
					if (m->first[2] == mIdx[2] || mIdx[2] == '-') {
						if (m->first[3] == mIdx[3] || mIdx[3] == '-') {
							for (int mi = 0; mi < m->second.size(); mi++) {
								if (m->second[mi] >= score) {
									ans++;
								}
							}
						}
					}
				}
			}
		}
		answer.push_back(ans);
	}

	return answer;
}