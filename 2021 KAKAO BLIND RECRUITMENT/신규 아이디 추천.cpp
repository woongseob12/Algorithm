/* 
Ǯ�� �ð�: 01:26 ~ 01:57(31��)
�ð� ���⵵: �ڷᱸ������ �̿��Ͽ� O(N)���� Ǯ��
���� : 
������ ����� �ܰ躰�� �Լ��� ���� ����
����� : 
- 1�� : �ƽ�Ű�ڵ��� ������ �������� ó����
- 2�� : change6(string id) �Լ��� while���� ��ġ�� ret�� �ʱ�ȭ
- 3�� : change5(string id) �Լ��� ���� ����� ��츦 ������� �ʰ� pop_back() ����
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
