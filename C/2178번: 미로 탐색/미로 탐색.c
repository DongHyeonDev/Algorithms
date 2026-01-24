/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2178                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2178                           #+#        #+#      #+#    */
/*   Solved: 2026/01/24 18:01:36 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point data[10001];
    int front;
    int rear;
} Queue;

int N, M;
char maze[101][101];
int dist[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void init_queue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

void enqueue(Queue* q, int x, int y) {
    q->data[q->rear].x = x;
    q->data[q->rear].y = y;
    q->rear++;
}

Point dequeue(Queue* q) {
    return q->data[q->front++];
}

int is_empty(Queue* q) {
    return q->front == q->rear;
}

int bfs() {
    Queue q;
    init_queue(&q);
    
    enqueue(&q, 0, 0);
    dist[0][0] = 1;
    
    while (!is_empty(&q)) {
        Point p = dequeue(&q);
        int x = p.x;
        int y = p.y;
        
        if (x == N - 1 && y == M - 1) {
            return dist[x][y];
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (maze[nx][ny] == '1' && dist[nx][ny] == 0) {
                    dist[nx][ny] = dist[x][y] + 1;
                    enqueue(&q, nx, ny);
                }
            }
        }
    }
    
    return dist[N - 1][M - 1];
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", maze[i]);
    }
    
    printf("%d\n", bfs());
    
    return 0;
}