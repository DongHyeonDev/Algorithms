/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7569                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7569                           #+#        #+#      #+#    */
/*   Solved: 2026/01/28 11:05:24 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

typedef struct {
    int h, x, y;
} Point;

int M, N, H;
int box[100][100][100];
int dist[100][100][100];
int dh[] = {0, 0, 0, 0, 1, -1};
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};

Point queue[1000001];
int front, rear;

int bfs() {
    front = 0;
    rear = 0;
    
    // dist 배열 초기화
    memset(dist, -1, sizeof(dist));
    
    // 모든 익은 토마토를 큐에 넣기
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (box[h][i][j] == 1) {
                    queue[rear].h = h;
                    queue[rear].x = i;
                    queue[rear].y = j;
                    rear++;
                    dist[h][i][j] = 0;
                } else if (box[h][i][j] == -1) {
                    dist[h][i][j] = 0;  // 빈 칸은 0으로
                }
            }
        }
    }
    
    int max_days = 0;
    
    while (front < rear) {
        Point p = queue[front++];
        int h = p.h;
        int x = p.x;
        int y = p.y;
        
        for (int i = 0; i < 6; i++) {
            int nh = h + dh[i];
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nh >= 0 && nh < H && nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (dist[nh][nx][ny] == -1) {
                    dist[nh][nx][ny] = dist[h][x][y] + 1;
                    if (dist[nh][nx][ny] > max_days) {
                        max_days = dist[nh][nx][ny];
                    }
                    queue[rear].h = nh;
                    queue[rear].x = nx;
                    queue[rear].y = ny;
                    rear++;
                }
            }
        }
    }
    
    // 익지 않은 토마토가 남아있는지 확인
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (box[h][i][j] == 0 && dist[h][i][j] == -1) {
                    return -1;
                }
            }
        }
    }
    
    return max_days;
}

int main() {
    scanf("%d %d %d", &M, &N, &H);
    
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &box[h][i][j]);
            }
        }
    }
    
    printf("%d\n", bfs());
    
    return 0;
}