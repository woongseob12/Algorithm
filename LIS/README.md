# LIS(Longest Indreasing Subsequence)

![LIS](https://user-images.githubusercontent.com/55429912/107375250-df5b4b00-6b2b-11eb-8f4a-a925b7344162.jpg)

# 최장 증가 부분 수열
원소가 n개인 배열의 일부 원소를 골라내서 만든 부분 수열 중, 각 **원소가 오름차순으로 정렬**되어 있고, **길이가 최대인 부분 수열**을 **최장 증가 부분 수열**이라고 합니다.

# 사용 함수, 알고리즘 
- DP => O(N^2)
- lower_bound() => O(NlogN)
  - N번 확인 * lower_bound()를 이용하여 최댓값을 찾음 = O(N * logN)


# lower_bound()
```C++
ForwardIt lower_bound(Forward first, ForwardIt last, const T&value);
```
- lower_bound(first, last, x) 는 [first, last) 범위에서 **x 이상인 첫번째 원소의 위치**를 반환(iterator)
- lower_bound(first, last, x) - first 를 통하여 인덱스값을 반환 가능
  - *ex) lower_bound(v.begin(), v.end(), 0) - v.begin()*

