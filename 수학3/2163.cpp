#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	// ������ ���̸� 1�� ���� : N -1
	// N���� ���� ���븦 ���̸� 1�� ���� : N * (M - 1) 
	cout << N -1 + N * (M - 1) << endl;
}