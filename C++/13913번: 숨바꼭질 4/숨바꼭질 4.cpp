/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 13913                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/13913                          #+#        #+#      #+#    */
/*   Solved: 2026/02/28 12:59:29 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int dist[MAX];
int from[MAX];

int main() {
    int N, K;
    cin >> N >> K;
    
    fill(dist, dist + MAX, -1);
    fill(from, from + MAX, -1);
    
    queue<int> q;
    dist[N] = 0;
    q.push(N);
    
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x == K) break;
        
        for (int next : {x - 1, x + 1, x * 2}) {
            if (next < 0 || next >= MAX) continue;
            if (dist[next] != -1) continue;
            dist[next] = dist[x] + 1;
            from[next] = x;
            q.push(next);
        }
    }
    
    cout << dist[K] << "\n";
    
    // 역추적: K → N 방향으로 from 따라가기
    vector<int> path;
    int cur = K;
    while (cur != -1) {
        path.push_back(cur);
        cur = from[cur];
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i];
        if (i + 1 < (int)path.size()) cout << " ";
    }
    cout << "\n";
    
    return 0;
}