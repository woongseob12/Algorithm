# LCA(Lowest Common Ancestor)

<img width="797" alt="LCA" src="https://user-images.githubusercontent.com/55429912/107801315-40408880-6da3-11eb-8887-382292d2772b.png">

# 최소 공통 조상
LCA란, 트리상에서 어떤 두 정점 u, v가 있을 때, u이거나 u의 조상이면서 동시에 v이거나 v의 조상인 노드들 중 가장 깊은 노드입니다.

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

