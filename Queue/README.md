# Queue

![q](https://user-images.githubusercontent.com/55429912/116702210-c9ab4280-aa03-11eb-9da3-e12f0aaaf9bb.png)

# 특징
- FIFO(First In First Out)

# 사용법

```C++
#include <queue>    
queue<int> q;
q.push(1);  // 큐에 1의 값 삽입
q.front();  // 큐의 최상위 데이터를 반환;
q.pop();    // 큐의 최상위 데이터(1)를 제거;      
```

# 시간 복잡도
- 삽입: O(1)  // 데이터를 맨 뒤에 삽입
- 삭제: O(1)  // 맨 위의 데이터를 삭제
- 검색: O(N)  // 특정 데이터를 찾을 때까지 수행

# 적용 가능 문제 
- <a href = https://www.acmicpc.net/problem/1158 >1158번 요세푸스 문제</a> 
- <a href = https://www.acmicpc.net/problem/1966 >1966번 프린터 큐</a> 
- <a href = https://www.acmicpc.net/problem/2164 >2164번 카드2</a>  
