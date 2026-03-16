/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1197                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1197                           #+#        #+#      #+#    */
/*   Solved: 2026/03/16 13:35:33 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001], rnk[10001];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra == rb) return false;  // 사이클 → 선택 안 함
    if (rnk[ra] < rnk[rb])      parent[ra] = rb;
    else if (rnk[ra] > rnk[rb]) parent[rb] = ra;
    else                        { parent[rb] = ra; rnk[ra]++; }
    return true;
}

int main() {
    int V, E;
    cin >> V >> E;
    
    // (가중치, u, v) 형태로 저장 후 가중치 기준 정렬
    vector<tuple<int,int,int>> edges(E);
    for (auto& [w, u, v] : edges) cin >> u >> v >> w;
    sort(edges.begin(), edges.end());
    
    for (int i = 1; i <= V; i++) parent[i] = i;
    
    long long total = 0;
    int count = 0;
    for (auto [w, u, v] : edges) {
        if (unite(u, v)) {
            total += w;
            if (++count == V - 1) break;  // V-1개 선택 완료
        }
    }
    
    cout << total << "\n";
    return 0;
}