/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4803                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4803                           #+#        #+#      #+#    */
/*   Solved: 2026/03/10 13:24:56 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int parent[501];
bool hasCycle[501];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra == rb) {
        hasCycle[ra] = true;    // 같은 집합 연결 → 사이클
    } else {
        parent[rb] = ra;
        hasCycle[ra] = hasCycle[ra] || hasCycle[rb];
    }
}

int main() {
    int n, m, caseNum = 1;
    while (cin >> n >> m && (n || m)) {
        // 초기화
        for (int i = 1; i <= n; i++) { parent[i] = i; hasCycle[i] = false; }
        
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            unite(a, b);
        }
        
        // 각 루트별로 사이클 없는 연결 요소 = 트리
        int treeCount = 0;
        set<int> roots;
        for (int i = 1; i <= n; i++) {
            int r = find(i);
            if (roots.insert(r).second && !hasCycle[r])
                treeCount++;
        }
        
        if (treeCount == 0)
            cout << "Case " << caseNum << ": No trees.\n";
        else if (treeCount == 1)
            cout << "Case " << caseNum << ": There is one tree.\n";
        else
            cout << "Case " << caseNum << ": A forest of " << treeCount << " trees.\n";
        
        caseNum++;
    }
    
    return 0;
}