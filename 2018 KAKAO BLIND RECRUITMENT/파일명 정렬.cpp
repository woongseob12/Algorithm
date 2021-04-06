#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

//vector<string> files = {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
//vector<string> files = { "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" };
vector<string> files = { "az12f" , "bd12f" };
vector<string> solution(vector<string> files);

int main() {
	vector<string> answer = solution(files);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;
}

bool cmp(string a, string b) {
	string ah, bh, an, bn, at, bt;
	int i, j;
	// HEAD 贸府
	for (i = 0; i < a.length(); i++) {
		if (a[i] >= '0' && a[i] <= '9') { break; }
		else {
			if (a[i] >= 'a' && a[i] <= 'z') { ah += (a[i] - 32); }
			else { ah += a[i]; }
		}
	}
	for (j = 0; j < b.length(); j++) {
		if (b[j] >= '0' && b[j] <= '9') { break; }
		else {
			if (b[j] >= 'a' && b[j] <= 'z') { bh += (b[j] - 32); }
			else { bh += b[j]; }
		}
	}
	if (ah != bh) { return ah < bh; }
	// NUMBER 贸府
	for (; i < a.length(); i++) {
		if (a[i] >= '0' && a[i] <= '9') { an += a[i]; }
		else { break; }
	}
	for (; j < b.length(); j++) {
		if (b[j] >= '0' && b[j] <= '9') { bn += b[j]; }
		else { break; }
	}
	int anCmp = stoi(an);
	int bnCmp = stoi(bn);
	if (anCmp != bnCmp) { return anCmp < bnCmp; }
	// TAIL
	return 0;
}

vector<string> solution(vector<string> files) {
	stable_sort(files.begin(), files.end(), cmp);
	return files;
}