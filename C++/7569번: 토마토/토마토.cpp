/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7569                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7569                           #+#        #+#      #+#    */
/*   Solved: 2026/01/28 11:05:32 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int M, N, H;
int box[100][100][100];
int dist[100][100][100];

// 6방향: 위, 아래, 왼쪽, 오른쪽, 앞, 뒤
int dh[] = {0, 0, 0, 0, 1, -1};
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};

int bfs() {
    queue<tuple<int, int, int>> q;
    
    // 모든 익은 토마토를 큐에 넣기
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (box[h][i][j] == 1) {
                    q.push({h, i, j});
                    dist[h][i][j] = 0;
                } else if (box[h][i][j] == 0) {
                    dist[h][i][j] = -1;
                }
            }
        }
    }
    
    int max_days = 0;
    
    while (!q.empty()) {
        auto [h, x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 6; i++) {
            int nh = h + dh[i];
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nh >= 0 && nh < H && nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (dist[nh][nx][ny] == -1 && box[nh][nx][ny] == 0) {
                    dist[nh][nx][ny] = dist[h][x][y] + 1;
                    max_days = max(max_days, dist[nh][nx][ny]);
                    q.push({nh, nx, ny});
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
    cin >> M >> N >> H;
    
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> box[h][i][j];
            }
        }
    }
    
    cout << bfs() << "\n";
    
    return 0;
}