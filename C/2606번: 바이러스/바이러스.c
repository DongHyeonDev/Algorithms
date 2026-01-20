/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2606                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2606                           #+#        #+#      #+#    */
/*   Solved: 2026/01/20 13:15:27 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} Vector;

Vector graph[101];
int visited[101];
int count_infected = 0;

void init_vector(Vector* v) {
    v->capacity = 4;
    v->size = 0;
    v->data = (int*)malloc(v->capacity * sizeof(int));
}

void push_back(Vector* v, int value) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void dfs(int node) {
    visited[node] = 1;
    count_infected++;
    
    for (int i = 0; i < graph[node].size; i++) {
        int next = graph[node].data[i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    // 벡터 초기화
    for (int i = 1; i <= N; i++) {
        init_vector(&graph[i]);
    }
    
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        push_back(&graph[u], v);
        push_back(&graph[v], u);
    }
    
    // 1번 컴퓨터에서 DFS 시작
    dfs(1);
    
    // 1번 컴퓨터는 제외하고 출력
    printf("%d\n", count_infected - 1);
    
    // 메모리 해제
    for (int i = 1; i <= N; i++) {
        free(graph[i].data);
    }
    
    return 0;
}