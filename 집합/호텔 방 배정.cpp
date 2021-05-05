#include <string>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;

vector<bool> visit;
unordered_map<ll, ll> m;

ll next(ll num) {
	if (m[num] == 0)
		return num;
	else
		return m[num] = next(m[num]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	for (int i = 0; i < room_number.size(); i++) {
		ll n = next(room_number[i]);
		answer.push_back(n);
		// 다음 방 설정 필수!
		m[n] = n + 1;
	}
	return answer;
}