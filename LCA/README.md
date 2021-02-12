# LCA(Lowest Common Ancestor)

![LIS](https://user-images.githubusercontent.com/55429912/107375250-df5b4b00-6b2b-11eb-8f4a-a925b7344162.jpg)

# 최소 공통 조상


# 알고리즘 
1. 모든 노드에 대한 깊이(depth)를 계산
2. 최소 공통 조상을 찾을 두 노드를 확인
  - 먼저 두 노드의 깊이가 동일하도록 거슬러 오름
  - 이후 부모가 같아질 때까지 반복적으로 두 노드의 부모 방향으로 거슬러 오름
3. 모든 LCA(a, b) 연산에 대하여 2번의 과정을 반복

# LCA
```C
int lca(int n1, int n2) {
  while(depth[n1] != depth[n2]) {
    if(depth[n1] > depth[n2]) {
      n1 = parent[n1];
    }
    else {
      n2 = parent[n2];
    }
  }
  while(n1 != n2) {
    n1 = parent[n1];
    n2 = parent[n2];
  }
  return n1;
}
```

