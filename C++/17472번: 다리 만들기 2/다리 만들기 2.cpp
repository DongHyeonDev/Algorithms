/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17472                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17472                          #+#        #+#      #+#    */
/*   Solved: 2026/03/20 15:34:01 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int grid[10][10], island[10][10];
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
int parent[7];

int find(int x) { return parent[x]==x ? x : parent[x]=find(parent[x]); }
bool unite(int a, int b) {
    int ra=find(a), rb=find(b);
    if (ra==rb) return false;
    parent[rb]=ra; return true;
}

int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++) cin >> grid[i][j];
    
    // 1단계: BFS로 섬 번호 부여
    int islandCnt = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (grid[i][j]!=1 || island[i][j]) continue;
            ++islandCnt;
            queue<pair<int,int>> q;
            q.push({i,j}); island[i][j]=islandCnt;
            while (!q.empty()) {
                auto [r,c] = q.front(); q.pop();
                for (int d=0; d<4; d++) {
                    int nr=r+dx[d], nc=c+dy[d];
                    if (nr<0||nr>=N||nc<0||nc>=M) continue;
                    if (grid[nr][nc]==1 && !island[nr][nc]) {
                        island[nr][nc]=islandCnt;
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
    
    // 2단계: 다리 탐색 (직선으로 바다를 건너는 경우)
    vector<tuple<int,int,int>> edges;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (!grid[i][j]) continue;
            int src = island[i][j];
            for (int d=0; d<4; d++) {
                int r=i+dx[d], c=j+dy[d], len=0;
                while (r>=0&&r<N&&c>=0&&c<M&&grid[r][c]==0) {
                    len++; r+=dx[d]; c+=dy[d];
                }
                if (r>=0&&r<N&&c>=0&&c<M
                    && grid[r][c]==1
                    && island[r][c]!=src
                    && len>=2)
                    edges.push_back({len, src, island[r][c]});
            }
        }
    }
    
    // 3단계: 크루스칼 MST
    sort(edges.begin(), edges.end());
    for (int i=1; i<=islandCnt; i++) parent[i]=i;
    
    int total=0, cnt=0;
    for (auto [w,u,v] : edges) {
        if (unite(u,v)) {
            total+=w;
            if (++cnt==islandCnt-1) break;
        }
    }
    
    cout << (cnt==islandCnt-1 ? total : -1) << "\n";
    return 0;
}