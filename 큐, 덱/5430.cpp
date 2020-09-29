#pragma warning (disable : 4996)
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);

	for (int TC = 0; TC < tc; TC++) {
		// 실행할 명령어
		string s;
		cin >> s;
		deque<char> func;
		int sSize = s.size();
		for (int i = 0; i < sSize; i++) {
			func.push_back(s[i]);
		}

		// 배열 크기
		int n;
		scanf("%d", &n);
		deque<int> ans;

		// 배열 원소 값;
		string elem;
		cin >> elem;
		// 앞 괄호 제거
		string val = "";
		elem.erase(elem.begin());
		while (!elem.empty()) {
			if (elem[0] == ',' || elem[0] == ']') {
				if(val != ""){
					ans.push_back(stoi(val));
				}
				val = "";
			}
			else {
				val += elem.front();
			}
			elem.erase(elem.begin());
		}

		// 명령문 실행
		bool error = false;
		int r = 0;
		while (!func.empty()) {
			if (func.front() == 'R') {
				r++;
			}
			else {
				if (ans.empty()) {
					error = true;
					break;
				}
				if (r % 2 == 0) {
					ans.pop_front();
				}
				else {
					ans.pop_back();
				}
			}
			func.pop_front();
		}
		if (error) {
			printf("error\n");
		}
		else {
			int ansSize = ans.size();
			printf("[");
			if (r % 2 == 0) {
				for (int i = 0; i < ansSize; i++) {
					if (i == ansSize - 1) {
						printf("%d", ans[i]);
					}
					else {
						printf("%d,", ans[i]);
					}
				}
			}
			else {
				for (int i = ansSize - 1; i >= 0; i--) {
					if (i == 0) {
						printf("%d", ans[i]);
					}
					else {
						printf("%d,", ans[i]);
					}
				}
			}
			printf("]\n");
		}
	}
}


