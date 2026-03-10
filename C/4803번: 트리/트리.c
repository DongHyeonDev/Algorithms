/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4803                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4803                           #+#        #+#      #+#    */
/*   Solved: 2026/03/10 13:24:49 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_N 501

int parent[MAX_N];
int hasCycle[MAX_N]; // 해당 루트의 연결 요소가 사이클 포함 여부

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra == rb) {
        hasCycle[ra] = 1;   // 이미 연결 → 사이클
    } else {
        parent[rb] = ra;
        hasCycle[ra] |= hasCycle[rb];
    }
}

int main() {
    int n, m, caseNum = 1;
    
    while (scanf("%d %d", &n, &m) && (n || m)) {
        // 초기화
        for (int i = 1; i <= n; i++) { parent[i] = i; hasCycle[i] = 0; }
        
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            unite(a, b);
        }
        
        // 트리 개수 세기: 루트별로 사이클 없는 연결 요소
        int treeCount = 0;
        int visited[MAX_N] = {0};
        for (int i = 1; i <= n; i++) {
            int r = find(i);
            if (!visited[r]) {
                visited[r] = 1;
                if (!hasCycle[r]) treeCount++;
            }
        }
        
        if (treeCount == 0)
            printf("Case %d: No trees.\n", caseNum);
        else if (treeCount == 1)
            printf("Case %d: There is one tree.\n", caseNum);
        else
            printf("Case %d: A forest of %d trees.\n", caseNum, treeCount);
        
        caseNum++;
    }
    
    return 0;
}