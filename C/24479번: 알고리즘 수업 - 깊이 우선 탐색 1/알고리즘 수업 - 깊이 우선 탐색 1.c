/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 24479                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/24479                          #+#        #+#      #+#    */
/*   Solved: 2026/01/16 22:33:42 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* graph[100001];
int visited[100001];
int order_count = 1;

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void add_edge(int u, int v) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vertex = v;
    new_node->next = graph[u];
    graph[u] = new_node;
}

void sort_graph(int N) {
    for (int i = 1; i <= N; i++) {
        if (graph[i] == NULL) continue;
        
        // 연결 리스트를 배열로 변환
        int count = 0;
        Node* temp = graph[i];
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        
        int* arr = (int*)malloc(count * sizeof(int));
        temp = graph[i];
        for (int j = 0; j < count; j++) {
            arr[j] = temp->vertex;
            temp = temp->next;
        }
        
        // 정렬
        qsort(arr, count, sizeof(int), compare);
        
        // 다시 연결 리스트로
        while (graph[i] != NULL) {
            Node* del = graph[i];
            graph[i] = graph[i]->next;
            free(del);
        }
        
        for (int j = count - 1; j >= 0; j--) {
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->vertex = arr[j];
            new_node->next = graph[i];
            graph[i] = new_node;
        }
        
        free(arr);
    }
}

void dfs(int node) {
    visited[node] = order_count++;
    
    Node* temp = graph[node];
    while (temp != NULL) {
        if (visited[temp->vertex] == 0) {
            dfs(temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);
    
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    
    // 인접 리스트 정렬
    sort_graph(N);
    
    // DFS 시작
    dfs(R);
    
    // 결과 출력
    for (int i = 1; i <= N; i++) {
        printf("%d\n", visited[i]);
    }
    
    return 0;
}