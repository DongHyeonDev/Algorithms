/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 16928                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/16928                          #+#        #+#      #+#    */
/*   Solved: 2026/01/29 15:48:20 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int board[101];  // 사다리나 뱀이 있으면 도착 위치, 없으면 0
int dist[101];   // 각 칸까지의 최소 주사위 횟수
int queue[101];
int front, rear;

int bfs() {
    memset(dist, -1, sizeof(dist));
    front = 0;
    rear = 0;
    
    queue[rear++] = 1;
    dist[1] = 0;
    
    while (front < rear) {
        int cur = queue[front++];
        
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
                queue[rear++] = next;
            }
        }
    }
    
    return dist[100];
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    memset(board, 0, sizeof(board));
    
    // 사다리 정보 입력
    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        board[x] = y;
    }
    
    // 뱀 정보 입력
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        board[u] = v;
    }
    
    printf("%d\n", bfs());
    
    return 0;
}