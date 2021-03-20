#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
bool visit[26];

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	bool flag = true;
	for (int i = 0; i < skill_trees.size(); i++) {
		int k = 0;
		flag = true;
		memset(visit, false, sizeof(visit));
		for (int j = 0; j < skill.size(); j++) {
			if (visit[skill[j] - 'A']) { 
				flag = false;
				break;
			}
			for (; k < skill_trees[i].size(); k++) {
				visit[skill_trees[i][k] - 'A'] = true;
				if (skill[j] == skill_trees[i][k]) {
					break;
				}
			}
		}
		if (flag) {
			answer++;
		}
	}
	return answer;
}