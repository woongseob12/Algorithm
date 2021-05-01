#include <string>
#include <iostream>
#include <deque>
#define ll long long
using namespace std;

int priority(char op1, char op2);
ll cal(ll a, ll b, char op);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string exp;
	cin >> exp;
	deque<ll> n;
	deque<char> op;

	// 수식 분리 후 넣기
	string temp = "";
	temp += exp[0];
	for (int i = 1; i < exp.length(); i++) {
		if (exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-') {
			op.push_back(exp[i]);
			n.push_back(stoll(temp));
			temp = "";
		}
		else {
			temp += exp[i];
		}
	}
	n.push_back(stoll(temp));
	// 연산자 비교 
	while (op.size() >= 2) {
		if (priority(op.front(), op.back()) == 1) {
			ll a = n.front();
			n.pop_front();
			ll b = n.front();
			n.pop_front();
			n.push_front(cal(a, b, op.front()));
			op.pop_front();
		}
		else if (priority(op.front(), op.back()) == -1) {
			ll a = n.back();
			n.pop_back();
			ll b = n.back();
			n.pop_back();
			n.push_back(cal(b, a, op.back()));
			op.pop_back();
		}
		else {
			ll a = n.front();
			n.pop_front();
			ll b = n.front();
			ll c = n.back();
			n.pop_back();
			ll d = n.back();
			char opf = op.front();
			char opb = op.back();
			ll tf = cal(a, b, opf);
			ll tb = cal(d, c, opb);
			if (tf >= tb) {
				n.pop_front();
				op.pop_front();
				n.push_back(c);
				n.push_front(tf);
			}
			else {
				n.pop_back();
				op.pop_back();
				n.push_front(a);
				n.push_back(tb);
			}
		}
	}
	if (!op.empty()) {
		cout << cal(n.front(), n.back(), op.front()) << "\n";
	}
	else {
		cout << n.front() << "\n";
	}
}

int priority(char op1, char op2) {
	if ((op1 == '*' || op1 == '/') && (op2 == '*' || op2 == '/')) {
		return 0;
	}
	else if ((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-')) {
		return 0;
	}
	else if (op1 == '*' || op1 == '/') {
		return 1;
	}
	return -1;
}

ll cal(ll a, ll b, char op) {
	switch (op)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
}