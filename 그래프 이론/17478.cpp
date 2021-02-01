#include <iostream>
#include <string>
using namespace std;

int N;
string s[] = {	"��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n",
				"\"����Լ��� ������?\"\n",
				"\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n",
				"���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n",
				"���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n",
				"\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n",
				"��� �亯�Ͽ���.\n"
};
void rec(int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	cout << s[0];
	rec(0);
}

void rec(int cnt) {
	if (cnt == N) {
		for (int i = 0; i < cnt; i++) {
			cout << "____";
		}
		cout << s[1];

		for (int si = 5; si <= 6; si++) {
			for (int i = 0; i < cnt; i++) {
				cout << "____";
			}
			cout << s[si];
		}
		return;
	}
	for (int si = 1; si <= 4; si++) {
		for (int i = 0; i < cnt; i++) {
			cout << "____";
		}
		cout << s[si];
	}
	rec(cnt + 1);
	for (int i = 0; i < cnt; i++) {
		cout << "____";
	}
	cout << s[6];

}