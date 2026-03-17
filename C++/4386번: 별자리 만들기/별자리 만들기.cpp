/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4386                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4386                           #+#        #+#      #+#    */
/*   Solved: 2026/03/17 12:19:53 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int parent[101];

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
    int n;
    cin >> n;
    
    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    
    // 모든 쌍의 거리를 간선으로 생성 (완전 그래프)
    vector<tuple<double,int,int>> edges;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            double dx = x[i]-x[j], dy = y[i]-y[j];
            edges.push_back({sqrt(dx*dx + dy*dy), i, j});
        }
    sort(edges.begin(), edges.end());
    
    for (int i = 0; i < n; i++) parent[i] = i;
    
    double total = 0.0;
    int count = 0;
    for (auto [d, u, v] : edges) {
        if (unite(u, v)) {
            total += d;
            if (++count == n - 1) break;
        }
    }
    
    cout << fixed << setprecision(2) << total << "\n";
    return 0;
}