#pragma warning (disable:4996)
#include <cstdio>
#include <string>
using namespace std;

int deque[10000];
int first, last;
const int top = 9999;

void push_front(int n);
void push_back(int n);
int pop_front();
int pop_back();
int size();
bool empty();
int front();
int back();

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char str[11];
		scanf("%s", str);
		if (strcmp(str,"push_front") == 0) {
			int val;
			scanf("%d", &val);
			push_front(val);
		}
		else if (strcmp(str, "push_back") == 0) {
			int val;
			scanf("%d", &val);
			push_back(val);
		}
		else if (strcmp(str, "pop_front") == 0) {
			printf("%d\n", pop_front());
		}
		else if (strcmp(str, "pop_back") == 0) {
			printf("%d\n", pop_back());
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", size());
		}
		else if (strcmp(str, "empty") == 0) {
			printf("%d\n", empty());
		}
		else if (strcmp(str, "front") == 0) {
			printf("%d\n", front());
		}
		else if (strcmp(str, "back") == 0) {
			printf("%d\n", back());
		}
	}
}

void push_front(int n)
{
	first--;
	if (first < 0) {
		first = top;
	}
	deque[first] = n;
}

void push_back(int n)
{
	deque[last] = n;
	last++;
	if (last > top) {
		last = 0;
	}
}

int pop_front()
{
	if (empty()) {
		return -1;
	}
	int val = deque[first];
	first++;
	if (first > top) {
		first = 0;
	}
	return val;
}

int pop_back()
{
	if (empty()) {
		return -1;
	}
	last--;
	if (last < 0) {
		last = top;
	}
	return deque[last];
}

int size()
{
	if (last >= first) {
		return last - first;
	}
	else {
		return last + top + 1 - first;
	}
}

bool empty()
{
	return last == first;
}

int front()
{
	if (empty()) {
		return -1;
	}
	return deque[first];
}

int back()
{
	if (empty()) {
		return -1;
	}
	int val = last - 1;
	if (val < 0) {
		val = top;
	}
	return deque[val];
}