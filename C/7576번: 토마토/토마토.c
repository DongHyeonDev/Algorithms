/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7576                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7576                           #+#        #+#      #+#    */
/*   Solved: 2026/01/27 10:53:05 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point data[1000001];
    int front;
    int rear;
} Queue;

int M, N;
int box[1000][1000];
int dist[1000][1000];
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

int max(int a, int b) {
    return a > b ? a : b;
}

int bfs() {
    Queue q;
    init_queue(&q);
    
    // 모든 익은 토마토를 큐에 넣기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 1) {
                enqueue(&q, i, j);
                dist[i][j] = 0;
            } else if (box[i][j] == 0) {
                dist[i][j] = -1;
            }
        }
    }
    
    int max_days = 0;
    
    while (!is_empty(&q)) {
        Point p = dequeue(&q);
        int x = p.x;
        int y = p.y;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (dist[nx][ny] == -1 && box[nx][ny] == 0) {
                    dist[nx][ny] = dist[x][y] + 1;
                    max_days = max(max_days, dist[nx][ny]);
                    enqueue(&q, nx, ny);
                }
            }
        }
    }
    
    // 익지 않은 토마토가 남아있는지 확인
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 0 && dist[i][j] == -1) {
                return -1;
            }
        }
    }
    
    return max_days;
}

int main() {
    scanf("%d %d", &M, &N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &box[i][j]);
        }
    }
    
    printf("%d\n", bfs());
    
    return 0;
}