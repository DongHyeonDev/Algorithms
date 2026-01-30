/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2206                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2206                           #+#        #+#      #+#    */
/*   Solved: 2026/01/30 12:36:50 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int N, M;
char map[1000][1001];
int dist[1000][1000][2];  // [x][y][벽을 부쉈는지 여부]
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs() {
    queue<tuple<int, int, int>> q;
    memset(dist, -1, sizeof(dist));
    
    q.push({0, 0, 0});  // x, y, broken
    dist[0][0][0] = 1;
    
    while (!q.empty()) {
        auto [x, y, broken] = q.front();
        q.pop();
        
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
                    q.push({nx, ny, broken});
                }
            }
            // 이동할 곳이 벽인 경우
            else if (map[nx][ny] == '1') {
                // 아직 벽을 부수지 않았다면 부수고 이동
                if (broken == 0 && dist[nx][ny][1] == -1) {
                    dist[nx][ny][1] = dist[x][y][broken] + 1;
                    q.push({nx, ny, 1});
                }
            }
        }
    }
    
    return -1;
}

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }
    
    cout << bfs() << "\n";
    
    return 0;
}