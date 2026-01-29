/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 16928                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/16928                          #+#        #+#      #+#    */
/*   Solved: 2026/01/29 15:48:24 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[101];  // 사다리나 뱀이 있으면 도착 위치, 없으면 0
int dist[101];   // 각 칸까지의 최소 주사위 횟수

int bfs() {
    queue<int> q;
    memset(dist, -1, sizeof(dist));
    
    q.push(1);
    dist[1] = 0;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (cur == 100) {
            return dist[100];
        }
        
        // 주사위 1~6 굴리기
        for (int dice = 1; dice <= 6; dice++) {
            int next = cur + dice;
            
            if (next > 100) continue;
            
            // 사다리나 뱀이 있으면 이동
            if (board[next] != 0) {
                next = board[next];
            }
            
            // 아직 방문하지 않은 칸이면
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    
    return dist[100];
}

int main() {
    int N, M;
    cin >> N >> M;
    
    memset(board, 0, sizeof(board));
    
    // 사다리 정보 입력
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        board[x] = y;
    }
    
    // 뱀 정보 입력
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        board[u] = v;
    }
    
    cout << bfs() << "\n";
    
    return 0;
}