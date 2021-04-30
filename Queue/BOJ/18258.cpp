#pragma warning (disable : 4996)
#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 2000000;
int first, last = -1;
int queue[MAX + 1];

void push();
int pop();
int size();
bool empty();
int front();
int back();

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char command[6];
		scanf("%s", command);
		if (strcmp(command,"push") == 0) {
			push();
		}
		else if (strcmp(command, "pop") == 0) {
			printf("%d\n", pop());
		}
		else if (strcmp(command, "size") == 0) {
			printf("%d\n", size());
		}
		else if (strcmp(command, "empty") == 0) {
			printf("%d\n", empty());
		}
		else if (strcmp(command, "front") == 0) {
			printf("%d\n", front());
		}
		else if (strcmp(command, "back") == 0) {
			printf("%d\n", back());
		}
		command[0] = '\0';		
	}
}

void push() 
{
	int val;
	cin >> val;
	last++;
	queue[last] = val;
}

int pop()
{
	if (empty()) {
		return -1;
	}
	else {
		first++;
		return queue[first - 1];
	}
}

int size()
{
	return last - first + 1;
}

bool empty()
{
	return last < first;
}

int front()
{
	if (empty()) {
		return -1;
	}
	else {
		return queue[first];
	}
}

int back()
{
	if (empty()) {
		return -1;
	}
	else {
		return queue[last];
	}
}