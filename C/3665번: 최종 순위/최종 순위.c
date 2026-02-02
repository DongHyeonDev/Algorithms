/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 3665                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/3665                           #+#        #+#      #+#    */
/*   Solved: 2026/02/02 12:36:09 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int n, m;
int last_year[501];
int graph[501][501];  // graph[i][j] = 1이면 i가 j보다 순위가 높음
int indegree[501];
int queue[501];
int result[501];
int front, rear;

int topology_sort() {
    int cnt = 0;
    front = 0;
    rear = 0;
    
    // 진입 차수가 0인 정점 찾기
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    while (front < rear) {
        // 큐에 원소가 2개 이상이면 순위를 확정할 수 없음
        if (rear - front > 1) {
            return -1;  // 확실한 순위를 찾을 수 없음
        }
        
        int cur = queue[front++];
        result[cnt++] = cur;
        
        for (int next = 1; next <= n; next++) {
            if (graph[cur][next]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    queue[rear++] = next;
                }
            }
        }
    }
    
    // 모든 정점을 방문하지 못했으면 사이클 존재
    if (cnt != n) {
        return 0;  // IMPOSSIBLE
    }
    
    return 1;  // 성공
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d", &n);
        
        memset(graph, 0, sizeof(graph));
        memset(indegree, 0, sizeof(indegree));
        
        // 작년 순위 입력
        for (int i = 0; i < n; i++) {
            scanf("%d", &last_year[i]);
        }
        
        // 작년 순위를 기반으로 그래프 생성
        // 순위가 높은 팀 -> 낮은 팀으로 간선
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                graph[last_year[i]][last_year[j]] = 1;
                indegree[last_year[j]]++;
            }
        }
        
        scanf("%d", &m);
        
        // 상대적 순위가 바뀐 쌍 처리
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            
            // 간선 방향 뒤집기
            if (graph[a][b]) {
                graph[a][b] = 0;
                graph[b][a] = 1;
                indegree[b]--;
                indegree[a]++;
            } else {
                graph[b][a] = 0;
                graph[a][b] = 1;
                indegree[a]--;
                indegree[b]++;
            }
        }
        
        int res = topology_sort();
        
        if (res == 0) {
            printf("IMPOSSIBLE\n");
        } else if (res == -1) {
            printf("?\n");
        } else {
            for (int i = 0; i < n; i++) {
                if (i > 0) printf(" ");
                printf("%d", result[i]);
            }
            printf("\n");
        }
    }
    
    return 0;
}