/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1717                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1717                           #+#        #+#      #+#    */
/*   Solved: 2026/03/11 13:45:33 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, rnk;

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]); // 경로 압축
    return parent[x];
}

void unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra == rb) return;
    // 랭크 기반 합치기 (트리 높이 균형 유지)
    if (rnk[ra] < rnk[rb])      parent[ra] = rb;
    else if (rnk[ra] > rnk[rb]) parent[rb] = ra;
    else { parent[rb] = ra; rnk[ra]++; }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    parent.resize(n + 1);
    rnk.resize(n + 1, 0);
    for (int i = 0; i <= n; i++) parent[i] = i;
    
    for (int i = 0; i < m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) {
            unite(a, b);
        } else {
            cout << (find(a) == find(b) ? "YES" : "NO") << "\n";
        }
    }
    
    return 0;
}