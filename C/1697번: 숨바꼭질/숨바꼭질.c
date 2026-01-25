/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1697                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1697                           #+#        #+#      #+#    */
/*   Solved: 2026/01/25 18:43:58 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

typedef struct {
    int data[100001];
    int front;
    int rear;
} Queue;

int N, K;
int visited[100001];

void init_queue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

void enqueue(Queue* q, int value) {
    q->data[q->rear++] = value;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

int is_empty(Queue* q) {
    return q->front == q->rear;
}

int bfs() {
    Queue q;
    init_queue(&q);
    
    enqueue(&q, N);
    visited[N] = 0;
    
    while (!is_empty(&q)) {
        int pos = dequeue(&q);
        
        if (pos == K) {
            return visited[pos];
        }
        
        // 3가지 이동 방법
        int next[3] = {pos - 1, pos + 1, pos * 2};
        
        for (int i = 0; i < 3; i++) {
            int npos = next[i];
            
            if (npos >= 0 && npos <= 100000 && visited[npos] == -1) {
                visited[npos] = visited[pos] + 1;
                enqueue(&q, npos);
            }
        }
    }
    
    return visited[K];
}

int main() {
    scanf("%d %d", &N, &K);
    
    memset(visited, -1, sizeof(visited));
    
    printf("%d\n", bfs());
    
    return 0;
}