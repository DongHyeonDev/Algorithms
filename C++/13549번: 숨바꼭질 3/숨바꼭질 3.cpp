/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 13549                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/13549                          #+#        #+#      #+#    */
/*   Solved: 2026/02/06 16:11:30 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

#define MAX 100001

int dist[MAX];

int bfs(int N, int K) {
    deque<int> dq;
    memset(dist, -1, sizeof(dist));
    
    dist[N] = 0;
    dq.push_back(N);
    
    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();
        
        if (cur == K) {
            return dist[K];
        }
        
        // 순간이동 (비용 0)
        int next = cur * 2;
        if (next < MAX && dist[next] == -1) {
            dist[next] = dist[cur];
            dq.push_front(next);
        }
        
        // 걷기 -1 (비용 1)
        next = cur - 1;
        if (next >= 0 && dist[next] == -1) {
            dist[next] = dist[cur] + 1;
            dq.push_back(next);
        }
        
        // 걷기 +1 (비용 1)
        next = cur + 1;
        if (next < MAX && dist[next] == -1) {
            dist[next] = dist[cur] + 1;
            dq.push_back(next);
        }
    }
    
    return dist[K];
}

int main() {
    int N, K;
    cin >> N >> K;
    
    cout << bfs(N, K) << "\n";
    
    return 0;
}