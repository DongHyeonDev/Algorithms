/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 20040                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/20040                          #+#        #+#      #+#    */
/*   Solved: 2026/03/14 18:44:12 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    
    parent.resize(n);
    for (int i = 0; i < n; i++) parent[i] = i;
    
    int answer = 0;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        int ra = find(a), rb = find(b);
        if (ra == rb) { answer = i; break; } // 사이클 완성
        parent[rb] = ra;
    }
    
    cout << answer << "\n";
    return 0;
}