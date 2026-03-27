/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15647                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15647                          #+#        #+#      #+#    */
/*   Solved: 2026/03/27 12:50:07 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<pair<int,int>>> graph(N+1);
    for (int i=0;i<N-1;i++) {
        int u,v,d; cin>>u>>v>>d;
        graph[u].push_back({v,d}); graph[v].push_back({u,d});
    }
    
    vector<int> par(N+1,0), parW(N+1,0), sz(N+1,1), order;
    vector<long long> down(N+1,0), ans(N+1,0);
    vector<bool> visited(N+1,false);
    order.reserve(N);
    
    // BFS
    queue<int> q;
    q.push(1); visited[1]=true;
    while (!q.empty()) {
        int u=q.front(); q.pop(); order.push_back(u);
        for (auto [v,w]:graph[u]) if (!visited[v]) {
            visited[v]=true; par[v]=u; parW[v]=w; q.push(v);
        }
    }
    
    // 1단계: 역순으로 sz, down 계산 (리프 → 루트)
    for (int i=(int)order.size()-1;i>=0;i--) {
        int u=order[i];
        for (auto [c,w]:graph[u]) {
            if (c==par[u]) continue;
            sz[u] += sz[c];
            down[u] += down[c] + (long long)sz[c]*w;
        }
    }
    
    // 2단계: 리루팅 (루트 → 자식)
    ans[1] = down[1];
    for (int u:order) {
        for (auto [c,w]:graph[u]) {
            if (c==par[u]) continue;
            // c의 서브트리: w만큼 가까워짐 sz[c]개
            // 나머지 N-sz[c]개: w만큼 멀어짐
            ans[c] = ans[u] + (long long)(N - 2*sz[c])*w;
        }
    }
    
    for (int i=1;i<=N;i++) cout << ans[i] << "\n";
    return 0;
}