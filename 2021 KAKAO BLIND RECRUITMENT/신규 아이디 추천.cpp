/* 
풀이 시간: 01:26 ~ 01:57(31분)
시간 복잡도: 자료구조들을 이용하여 O(N)내로 풀이
구현 : 
문제의 명세대로 단계별로 함수를 통한 구현
디버깅 : 
- 1차 : 아스키코드의 덧셈을 뺄셈으로 처리함
- 2차 : change6(string id) 함수의 while문의 위치와 ret의 초기화
- 3차 : change5(string id) 함수의 덱이 비었을 경우를 고려하지 않고 pop_back() 수행
*/
#include <string>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

string solution(string new_id);
string change1(string id);
string change2(string id);
string change3(string id);
string change4(string id);
string change5(string id);
string change6(string id);
string change7(string id);

string solution(string new_id) {
	string answer = "";
	answer = change1(new_id);
	answer = change2(answer);
	answer = change3(answer);
	answer = change4(answer);
	answer = change5(answer);
	answer = change6(answer);
	answer = change7(answer);
	return answer;
}

string change1(string id) {
	for (int i = 0; i < id.size(); i++) {
		if (id[i] >= 'A' && id[i] <= 'Z') {
			id[i] += 32;
		}
	}
	return id;
}

string change2(string id) {
	queue<char> q;
	for (int i = 0; i < id.size(); i++) {
		if ((id[i] >= 'a' && id[i] <= 'z') || (id[i] >= '0' && id[i] <= '9') || id[i] == '-' || id[i] == '_' || id[i] == '.') {
			q.push(id[i]);
		}
	}
	string ret;
	while (!q.empty()) {
		ret += q.front();
		q.pop();
	}
	return ret;
}

string change3(string id) {
	deque<char> dq;
	for (int i = 0; i < id.size(); i++) {
		if (id[i] == '.') {
			if (dq.empty() || dq.back() != '.') {
				dq.push_back(id[i]);
			}
		}
		else {
			dq.push_back(id[i]);
		}
	}

	string ret;
	while (!dq.empty()) {
		ret += dq.front();
		dq.pop_front();
	}
	return ret;
}

string change4(string id) {
	deque<char> dq;
	for (int i = 0; i < id.size(); i++) {
		dq.push_back(id[i]);
	}
	if (dq.front() == '.') {
		dq.pop_front();
	}
	if (!dq.empty() && dq.back() == '.') {
		dq.pop_back();
	}

	string ret;
	while (!dq.empty()) {
		ret += dq.front();
		dq.pop_front();
	}
	return ret;
}

string change5(string id) {
	if (id.size() == 0) {
		id = "a";
	}
	return id;
}

string change6(string id) {
	deque<char> dq;
	string ret = id;
	if (id.size() >= 16) {
		for (int i = 0; i < 15; i++) {
			dq.push_back(id[i]);
		}
		ret = "";
		while (!dq.empty()) {
			ret += dq.front();
			dq.pop_front();
		}
		ret = change4(ret);
	}
	return ret;
}

string change7(string id) {
	if (id.size() <= 2) {
		while (id.size() < 3) {
			id += id[id.size() - 1];
		}
	}
	return id;
}
