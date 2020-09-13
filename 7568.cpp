#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<vector<int>> person;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int h, w;
		cin >> w >> h;
		person.push_back({ w, h });
	}
	for (int i = 0; i < person.size(); i++) {
		int grade = 1;
		for (int j = 0; j < person.size(); j++) {
			if (person[i][0] < person[j][0] && person[i][1] < person[j][1]) {
				grade++;
			}
		}
		cout << grade << " ";
	}
	cout << endl;
}