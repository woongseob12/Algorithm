#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	do
	{
		getline(cin, s);
		cout << s << endl;
	} while (s != "");
}