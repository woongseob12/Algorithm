#include <iostream>
#include <string>
using namespace std;

int fPtr, num, bPtr;
int queue[10000];
void push(int val);
int pop();
int qSize();
int qEmpty();
int qFront();
int qBack();

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int val;
			cin >> val;
			push(val);
		}
		else if (s == "pop") {
			cout << pop() << endl;
		}
		else if (s == "size") {
			cout << qSize() << endl;
		}
		else if (s == "empty") {
			cout << qEmpty() << endl;
		}
		else if (s == "front") {
			cout << qFront() << endl;
		}
		else if (s == "back") {
			cout << qBack() << endl;
		}
	}
}

void push(int val) {
	if (bPtr == 10000) {
		bPtr = 0;
	}
	queue[bPtr++] = val;
	num++;
}

int pop() {
	if (qSize() == 0) {
		return -1;
	}
	fPtr++;
	if (fPtr == 10000) {
		fPtr = 0;
	}
	num--;
	if (fPtr - 1 == -1) {
		return queue[9999];
	}
	return queue[fPtr - 1];
}

int qSize() {
	return num;
}

int qEmpty() {
	if (qSize() == 0) {
		return 1;
	}
	return 0;
}

int qFront() {
	if (qSize() == 0) {
		return -1;
	}
	return queue[fPtr];
}

int qBack() {
	if (qSize() == 0) {
		return -1;
	}
	if (bPtr - 1 == -1) {
		return queue[9999];
	}
	return queue[bPtr - 1];
}