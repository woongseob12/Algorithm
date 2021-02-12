# Segment Tree(세그먼트 트리)

주어진 쿼리에 대해 빠르게 응답하기 위해 만들어진 자료구조

![2](https://user-images.githubusercontent.com/55429912/107781485-4cb8e700-6d8b-11eb-9e53-3077c7c0aa6d.png)

**부모 노드** : x ~ y (x부터 y까지의 합의 범위)

**리프노드** : **입력 받은 데이터**

**루트 노드** : 데이터들의 총 합

Ex) arr[0] = 1, arr[1] = 2, ary[2] = 3일 경우, [0, 2]에 해당하는 노드의 값은 6

# 메모리 
- 최적화 : 세그먼트 트리의 전체 크기(배열)은 **2^k > 노드의 수**를 만족하는 최소 k에 2배인 값
  
        Ex) N = 12일 경우, 세그먼트 트리의 값은 2^4 * 2 = 32;
    ```C++
    int h = (int)ceil(log2(n));
    int treeSize = (1<< (h + 1));
    ```
- 가성비 :  노드의 수 * 4

# 초기화
```C
ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end)
{
    if (start == end)
        return tree[node] = arr[start];
 
    int mid = (start + end) / 2;
 
    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end); 
}
```
왼쪽 자식 : start ~ mid

오른쪽 자식 : mid + 1 ~ end

Ex)

*1번(루트)노드의 왼쪽 자식: (arr, tree, 2, start, mid)*

*1번(루트)노드의 오른쪽 자식: (arr, tree, 3, mid + 1, end)*

# 갱신
```C
void update(vector<ll> &tree, int node, int start, int end, int idx, ll diff)
{
    if (!(start <= idx && idx <= end)) {
        return;
    }

    tree[node] += diff;
 
    if(start != end) {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, idx, diff);
        update(tree, node * 2 + 1, mid + 1, end, idx, diff);
    }
 
}
```

# 구간 합
```C
ll sum(vector<ll> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
        
    if (left <= start && end <= right) { 
        return tree[node];
    }
 
    int mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right);
}
```
1. [left, right]와 [start, end]가 겹치지 않는 경우
    - 구간 합을 구하고자 하는 범위와 상관이 없는 경우
2. [left, right]가 [start, end]를 완전히 포함하는 경우
    - 구하고자 하는 구간 합 구간에 포함되는 경우
3. [start, end]가 [left, right]를 완전히 포함하는 경우 
    - 구하고자 하는 구간 합 범위보다는 크게 있지만 그 내부에 구하고자 하는 구간 합 범위가 있는 경우
4. [left, right]와 [start, end]가 겹쳐져 있는 경우(1,2,3을 제외한 나머지 경우)
    - left <= start <= right <= end같은 방식인 경우

출처: https://www.crocus.co.kr/648 [Crocus]