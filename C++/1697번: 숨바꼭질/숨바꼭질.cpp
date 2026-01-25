/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1697                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1697                           #+#        #+#      #+#    */
/*   Solved: 2026/01/25 18:44:05 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, K;
int visited[100001];

int bfs() {
    queue<int> q;
    q.push(N);
    visited[N] = 0;
    
    while (!q.empty()) {
        int pos = q.front();
        q.pop();
        
        // 동생을 찾으면 종료
        if (pos == K) {
            return visited[pos];
        }
        
        // 3가지 이동 방법
        int next[3] = {pos - 1, pos + 1, pos * 2};
        
        for (int i = 0; i < 3; i++) {
            int npos = next[i];
            
            if (npos >= 0 && npos <= 100000 && visited[npos] == -1) {
                visited[npos] = visited[pos] + 1;
                q.push(npos);
            }
        }
    }
    
    return visited[K];
}

int main() {
    cin >> N >> K;
    
    memset(visited, -1, sizeof(visited));
    
    cout << bfs() << "\n";
    
    return 0;
}