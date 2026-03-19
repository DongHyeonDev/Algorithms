/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 6497                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/6497                           #+#        #+#      #+#    */
/*   Solved: 2026/03/19 11:18:16 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[200001];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra == rb) return false;
    parent[rb] = ra;
    return true;
}

int main() {
    int m, n;
    while (cin >> m >> n && (m || n)) {
        for (int i = 0; i < m; i++) parent[i] = i;
        
        vector<tuple<int,int,int>> edges(n);
        long long total = 0;
        for (auto& [w, u, v] : edges) {
            cin >> u >> v >> w;
            total += w;
        }
        sort(edges.begin(), edges.end());  // 가중치 기준 정렬
        
        long long mst = 0;
        for (auto [w, u, v] : edges)
            if (unite(u, v)) mst += w;
        
        // 절약액 = 전체 합 - MST 합
        cout << total - mst << "\n";
    }
    return 0;
}