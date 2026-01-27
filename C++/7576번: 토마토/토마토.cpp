/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7576                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7576                           #+#        #+#      #+#    */
/*   Solved: 2026/01/27 10:52:56 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int M, N;
int box[1000][1000];
int dist[1000][1000];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs() {
    queue<pair<int, int>> q;
    
    // 모든 익은 토마토를 큐에 넣고 거리 0으로 초기화
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            } else if (box[i][j] == 0) {
                dist[i][j] = -1;
            }
        }
    }
    
    int max_days = 0;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (dist[nx][ny] == -1 && box[nx][ny] == 0) {
                    dist[nx][ny] = dist[x][y] + 1;
                    max_days = max(max_days, dist[nx][ny]);
                    q.push({nx, ny});
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
    cin >> M >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
        }
    }
    
    cout << bfs() << "\n";
    
    return 0;
}