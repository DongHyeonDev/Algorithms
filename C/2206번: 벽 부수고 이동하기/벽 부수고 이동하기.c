/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2206                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2206                           #+#        #+#      #+#    */
/*   Solved: 2026/01/30 12:36:43 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

typedef struct {
    int x, y, broken;
} State;

int N, M;
char map[1000][1001];
int dist[1000][1000][2];  // [x][y][벽을 부쉈는지 여부]
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

State queue[2000001];
int front, rear;

int bfs() {
    memset(dist, -1, sizeof(dist));
    front = 0;
    rear = 0;
    
    queue[rear].x = 0;
    queue[rear].y = 0;
    queue[rear].broken = 0;
    rear++;
    dist[0][0][0] = 1;
    
    while (front < rear) {
        State cur = queue[front++];
        int x = cur.x;
        int y = cur.y;
        int broken = cur.broken;
        
        if (x == N - 1 && y == M - 1) {
            return dist[x][y][broken];
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            
            // 이동할 곳이 빈 칸인 경우
            if (map[nx][ny] == '0') {
                if (dist[nx][ny][broken] == -1) {
                    dist[nx][ny][broken] = dist[x][y][broken] + 1;
                    queue[rear].x = nx;
                    queue[rear].y = ny;
                    queue[rear].broken = broken;
                    rear++;
                }
            }
            // 이동할 곳이 벽인 경우
            else if (map[nx][ny] == '1') {
                // 아직 벽을 부수지 않았다면 부수고 이동
                if (broken == 0 && dist[nx][ny][1] == -1) {
                    dist[nx][ny][1] = dist[x][y][broken] + 1;
                    queue[rear].x = nx;
                    queue[rear].y = ny;
                    queue[rear].broken = 1;
                    rear++;
                }
            }
        }
    }
    
    return -1;
}

int main() {
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) {
        scanf("%s", map[i]);
    }
    
    printf("%d\n", bfs());
    
    return 0;
}