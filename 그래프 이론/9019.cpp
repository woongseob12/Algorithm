#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int D(int n);
int S(int n);
int L(int n);
int R(int n);
string bfs(int start, int end);

int main()
{
	int TC;
	cin >> TC;
	while (TC--) {
		int start, end;
		cin >> start >> end;
		cout << bfs(start, end) << '\n';
	}
}

int D(int n) {
	return 2 * n % 10000;
}

int S(int n) {
	if (n == 0) {
		return 9999;
	}
	return n - 1;
}

int L(int n) {
	return (n * 10 + n / 1000) % 10000;
}

int R(int n) {
	return n / 10 + (n % 10) * 1000;
}

string bfs(int start, int end) {
	queue<pair<int, string>> q;
	vector<bool> visit(10000, false);
	q.push(make_pair(start, ""));
	while (!q.empty()) {
		start = q.front().first;
		string str = q.front().second;
		q.pop();
		if (start == end) {
			return str;
		}
		if (!visit[D(start)]) {
			q.push(make_pair(D(start), str + "D"));
			visit[D(start)] = true;
		}
		if (!visit[S(start)]) {
			q.push(make_pair(S(start), str + "S"));
			visit[S(start)] = true;
		}
		if (!visit[L(start)]) {
			q.push(make_pair(L(start), str + "L"));
			visit[L(start)] = true;
		}
		if (!visit[R(start)]) {
			q.push(make_pair(R(start), str + "R"));
			visit[R(start)] = true;
		}
	}
	return "\0";
}