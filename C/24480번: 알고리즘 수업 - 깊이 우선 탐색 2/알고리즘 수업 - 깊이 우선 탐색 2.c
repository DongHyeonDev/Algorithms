/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 24480                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/24480                          #+#        #+#      #+#    */
/*   Solved: 2026/01/17 21:57:33 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int** graph;
int* graph_size;
int* visited;
int order_count = 1;

int compare_desc(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

void dfs(int node) {
    visited[node] = order_count++;
    
    for (int i = 0; i < graph_size[node]; i++) {
        int next = graph[node][i];
        if (visited[next] == 0) {
            dfs(next);
        }
    }
}

int main() {
    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);
    
    // 동적 할당
    graph = (int**)malloc((N + 1) * sizeof(int*));
    graph_size = (int*)calloc(N + 1, sizeof(int));
    visited = (int*)calloc(N + 1, sizeof(int));
    
    // 각 정점마다 최대 M개의 간선 가능 (실제로는 더 적음)
    for (int i = 0; i <= N; i++) {
        graph[i] = (int*)malloc(N * sizeof(int));
    }
    
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][graph_size[u]++] = v;
        graph[v][graph_size[v]++] = u;
    }
    
    // 각 정점의 인접 리스트를 내림차순 정렬
    for (int i = 1; i <= N; i++) {
        qsort(graph[i], graph_size[i], sizeof(int), compare_desc);
    }
    
    // DFS 시작
    dfs(R);
    
    // 결과 출력
    for (int i = 1; i <= N; i++) {
        printf("%d\n", visited[i]);
    }
    
    // 메모리 해제
    for (int i = 0; i <= N; i++) {
        free(graph[i]);
    }
    free(graph);
    free(graph_size);
    free(visited);
    
    return 0;
}