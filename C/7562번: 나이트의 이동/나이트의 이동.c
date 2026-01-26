/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7562                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7562                           #+#        #+#      #+#    */
/*   Solved: 2026/01/26 12:42:53 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point data[90001];
    int front;
    int rear;
} Queue;

int l;
int visited[301][301];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

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

int bfs(int sx, int sy, int ex, int ey) {
    if (sx == ex && sy == ey) {
        return 0;
    }
    
    Queue q;
    init_queue(&q);
    
    enqueue(&q, sx, sy);
    visited[sx][sy] = 0;
    
    while (!is_empty(&q)) {
        Point p = dequeue(&q);
        int x = p.x;
        int y = p.y;
        
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < l && ny >= 0 && ny < l) {
                if (visited[nx][ny] == -1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    
                    if (nx == ex && ny == ey) {
                        return visited[nx][ny];
                    }
                    
                    enqueue(&q, nx, ny);
                }
            }
        }
    }
    
    return visited[ex][ey];
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d", &l);
        
        int sx, sy, ex, ey;
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        
        memset(visited, -1, sizeof(visited));
        
        printf("%d\n", bfs(sx, sy, ex, ey));
    }
    
    return 0;
}