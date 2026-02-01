/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2252                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2252                           #+#        #+#      #+#    */
/*   Solved: 2026/02/01 11:18:17 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[32001];
int indegree[32001];
int queue[32001];
int result[32001];
int front, rear;

void add_edge(int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = adj[u];
    adj[u] = node;
}

void topology_sort(int N) {
    front = 0;
    rear = 0;
    int idx = 0;
    
    // 진입 차수가 0인 정점을 큐에 넣기
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    while (front < rear) {
        int cur = queue[front++];
        result[idx++] = cur;
        
        // 현재 정점과 연결된 정점들의 진입 차수 감소
        for (Node* node = adj[cur]; node != NULL; node = node->next) {
            int next = node->vertex;
            indegree[next]--;
            
            if (indegree[next] == 0) {
                queue[rear++] = next;
            }
        }
    }
    
    // 결과 출력
    for (int i = 0; i < N; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

void free_graph(int N) {
    for (int i = 1; i <= N; i++) {
        Node* node = adj[i];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    memset(adj, 0, sizeof(adj));
    memset(indegree, 0, sizeof(indegree));
    
    for (int i = 0; i < M; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        add_edge(A, B);
        indegree[B]++;
    }
    
    topology_sort(N);
    
    free_graph(N);
    
    return 0;
}