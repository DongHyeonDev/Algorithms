/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1012                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1012                           #+#        #+#      #+#    */
/*   Solved: 2026/01/23 12:18:04 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int M, N, K;
int field[51][51];
int visited[51][51];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    visited[x][y] = 1;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (field[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d %d %d", &M, &N, &K);
        
        memset(field, 0, sizeof(field));
        memset(visited, 0, sizeof(visited));
        
        for (int i = 0; i < K; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            field[y][x] = 1;
        }
        
        int worm_count = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (field[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    worm_count++;
                }
            }
        }
        
        printf("%d\n", worm_count);
    }
    
    return 0;
}