/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 22967                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/22967                          #+#        #+#      #+#    */
/*   Solved: 2026/04/12 14:33:02 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<int> graph[305];
bool adj[305][305];
int dist_arr[305], par_arr[305];

void bfs(int src) {
    fill(dist_arr+1, dist_arr+N+1, -1);
    queue<int> q;
    dist_arr[src]=0; par_arr[src]=-1; q.push(src);
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int v:graph[u]) if (dist_arr[v]==-1) {
            dist_arr[v]=dist_arr[u]+1; par_arr[v]=u; q.push(v);
        }
    }
}

int main() {
    cin >> N;
    for (int i=0;i<N-1;i++) {
        int u,v; cin>>u>>v;
        graph[u].push_back(v); graph[v].push_back(u);
        adj[u][v]=adj[v][u]=true;
    }

    vector<pair<int,int>> newEdges;
    int diameter;

    if (N <= 4) {
        // 완전 그래프 → 지름 1
        diameter = 1;
        for (int i=1;i<=N;i++)
            for (int j=i+1;j<=N;j++)
                if (!adj[i][j]) newEdges.push_back({i,j});
    } else {
        // 트리 중심에 모든 노드 연결 → 지름 2
        bfs(1);
        int u=1; for (int i=1;i<=N;i++) if (dist_arr[i]>dist_arr[u]) u=i;
        bfs(u);
        int v=1; for (int i=1;i<=N;i++) if (dist_arr[i]>dist_arr[v]) v=i;
        int D=dist_arr[v];

        // u→v 경로 복원, 중심 선택
        vector<int> path;
        int cur=v;
        while (cur!=-1) { path.push_back(cur); cur=par_arr[cur]; }
        int center=path[D/2];

        diameter = 2;
        for (int i=1;i<=N;i++)
            if (i!=center && !adj[i][center])
                newEdges.push_back({i, center});
    }

    cout << newEdges.size() << "\n" << diameter << "\n";
    for (auto [a,b]:newEdges) cout << a << " " << b << "\n";
    return 0;
}