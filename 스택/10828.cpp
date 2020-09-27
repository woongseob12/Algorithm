#include <iostream>
#include <string>
using namespace std;

int index = -1; 
int stack[10000];

void push();
void pop();
void size();
void empty();
void top();

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") { push(); }
		else if (s == "pop") { pop(); }
		else if (s == "size") { size(); }
		else if (s == "empty") { empty(); }
		else if (s == "top") { top(); }
	}
}

void push()
{
	int n;
	cin >> n;
	index++;
	stack[index] = n;
}

void pop()
{
	if (index == -1) {
		cout << -1 << endl;
	}
	else {
		cout << stack[index] << endl;
		index--;
	}
}

void size()
{
	cout << index + 1 << endl;
}

void empty()
{
	if (index == -1) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
}

void top()
{
	if (index == -1) {
		cout << -1 << endl;
	}
	else {
		cout << stack[index] << endl;
	}
}
