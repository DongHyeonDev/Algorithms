/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4195                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4195                           #+#        #+#      #+#    */
/*   Solved: 2026/03/13 16:49:07 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int parent[200001], sz[200001];
int nextId;

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

int unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra == rb) return sz[ra];
    // 크기 기반 합치기 (작은 쪽 → 큰 쪽)
    if (sz[ra] < sz[rb]) { parent[ra] = rb; sz[rb] += sz[ra]; return sz[rb]; }
    else                  { parent[rb] = ra; sz[ra] += sz[rb]; return sz[ra]; }
}

int main() {
    int T; cin >> T;
    while (T--) {
        int F; cin >> F;
        
        unordered_map<string, int> idMap;
        nextId = 0;
        
        // 문자열 → 정수 ID 변환 (없으면 새로 등록)
        auto getId = [&](const string& name) -> int {
            auto it = idMap.find(name);
            if (it != idMap.end()) return it->second;
            idMap[name] = nextId;
            parent[nextId] = nextId;
            sz[nextId] = 1;
            return nextId++;
        };
        
        for (int i = 0; i < F; i++) {
            string a, b; cin >> a >> b;
            int ia = getId(a), ib = getId(b);
            cout << unite(ia, ib) << "\n";
        }
    }
    
    return 0;
}