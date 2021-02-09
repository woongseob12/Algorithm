# LIS(Longest Indreasing Subsequence)

![LIS](https://user-images.githubusercontent.com/55429912/107375250-df5b4b00-6b2b-11eb-8f4a-a925b7344162.jpg)

# 최장 증가 부분 수열
원소가 n개인 배열의 일부 원소를 골라내서 만든 부분 수열 중, 각 **원소가 오름차순으로 정렬**되어 있고, **길이가 최대인 부분 수열**을 **최장 증가 부분 수열**이라고 합니다.

# 사용 함수, 알고리즘 
- DP => O(N^2)
- lower_bound() => O(NlogN)
  - N번 확인 * lower_bound()를 이용하여 최댓값을 찾음 = O(N * logN)

# 기타 Method

```C++
stack.push(1);       
stack.top();        
stack.pop();       
stack.size();       
stack.empty();       
```

# 적용 가능 문제 
- <a href = https://www.acmicpc.net/problem/1725 >1725번 히스토그램</a> 
- <a href = https://www.acmicpc.net/problem/2493 >2493번 탑</a> 
- <a href = https://www.acmicpc.net/problem/9012 >9012번 괄호</a> 
- <a href = https://www.acmicpc.net/problem/10799 >10799번 쇠막대기</a> 
