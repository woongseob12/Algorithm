# Stack

![stack](https://user-images.githubusercontent.com/55429912/107362203-cc407f00-6b1b-11eb-948a-70d6d7cba657.png)


# 특징
- LIFO(Last In First Out)

# 사용법

```C++
#include <stack>    
stack<int> s;
s.push(1);  // 스택에 1의 값 삽입
s.top();    // 스택의 최상단 값(1) 출력;
s.pop();    // 스택의 최상단 값(1) 제거;      
```

# 시간 복잡도
- 삽입: O(1)  // 데이터를 맨 위에 삽입
- 삭제: O(1)  // 맨 위의 데이터를 삭제
- 검색: O(N)  // 특정 데이터를 찾을 때까지 수행

# 적용 가능 문제 
- <a href = https://www.acmicpc.net/problem/1725 >1725번 히스토그램</a> 
- <a href = https://www.acmicpc.net/problem/2493 >2493번 탑</a> 
- <a href = https://www.acmicpc.net/problem/9012 >9012번 괄호</a> 
- <a href = https://www.acmicpc.net/problem/10799 >10799번 쇠막대기</a> 
