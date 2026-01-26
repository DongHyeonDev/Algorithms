/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7562                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7562                           #+#        #+#      #+#    */
/*   Solved: 2026/01/26 12:42:59 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int l;
int visited[301][301];

// 나이트의 8가지 이동 방향
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int sx, int sy, int ex, int ey) {
    if (sx == ex && sy == ey) {
        return 0;
    }
    
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = 0;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < l && ny >= 0 && ny < l) {
                if (visited[nx][ny] == -1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    
                    if (nx == ex && ny == ey) {
                        return visited[nx][ny];
                    }
                    
                    q.push({nx, ny});
                }
            }
        }
    }
    
    return visited[ex][ey];
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        cin >> l;
        
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        
        memset(visited, -1, sizeof(visited));
        
        cout << bfs(sx, sy, ex, ey) << "\n";
    }
    
    return 0;
}