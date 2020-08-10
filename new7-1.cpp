#include <vector>

long long sum(std::vector<int>& a)
{
	long long n = 0;
	for (int i = 0; i < a.size(); i++) {
		n += a[i];
	}
	return n;
}
