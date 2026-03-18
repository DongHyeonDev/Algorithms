/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1774                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1774                           #+#        #+#      #+#    */
/*   Solved: 2026/03/18 14:15:30 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int parent[1001];

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
    int N, M;
    cin >> N >> M;
    
    vector<double> x(N+1), y(N+1);
    for (int i = 1; i <= N; i++) cin >> x[i] >> y[i];
    
    for (int i = 1; i <= N; i++) parent[i] = i;
    
    // 기존 연결 통로 먼저 유니온-파인드에 반영
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        unite(a, b);
    }
    
    // 모든 쌍의 거리를 간선으로 생성 (완전 그래프)
    vector<tuple<double,int,int>> edges;
    for (int i = 1; i <= N; i++)
        for (int j = i+1; j <= N; j++) {
            double dx = x[i]-x[j], dy = y[i]-y[j];
            edges.push_back({sqrt(dx*dx+dy*dy), i, j});
        }
    sort(edges.begin(), edges.end());
    
    // 크루스칼: 이미 연결된 쌍은 unite가 false를 반환하므로 자동 스킵
    double total = 0.0;
    for (auto [d, u, v] : edges)
        if (unite(u, v)) total += d;
    
    cout << fixed << setprecision(2) << total << "\n";
    return 0;
}