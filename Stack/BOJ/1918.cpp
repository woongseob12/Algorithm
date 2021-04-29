#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	
	stack<char> op;
	for (int i = 0; i < (int)str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			cout << str[i];
		}
		else if (str[i] == '(') {
			op.push(str[i]);
		}
		else if (str[i] == ')') {
			while (!op.empty() && op.top() !='(') {
				cout << op.top();
				op.pop();
			}
			if (op.top() == '(') { op.pop(); }
		}
		else if (str[i] == '+' || str[i] == '-') {
			while (!op.empty() && op.top() != '(') {
				cout << op.top();
				op.pop();
			}
			if (op.top() == '(') { op.pop(); }
			op.push(str[i]);
		}
		else {	// *, /
			while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
				cout << op.top();
				op.pop();
			}
			op.push(str[i]);
		}
	}

	while (!op.empty()) {
		if (op.top() != '(') {
			cout << op.top();
		}
		op.pop();
	}
}