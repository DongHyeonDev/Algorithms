/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1976                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1976                           #+#        #+#      #+#    */
/*   Solved: 2026/03/12 17:14:38 by dhkim0206     ###          ###   ##.kr    */
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

void unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra != rb) parent[rb] = ra;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    parent.resize(N + 1);
    for (int i = 0; i <= N; i++) parent[i] = i;
    
    // 인접 행렬 읽으며 연결된 도시 union
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            int conn; cin >> conn;
            if (conn) unite(i, j);
        }
    
    vector<int> plan(M);
    for (int i = 0; i < M; i++) cin >> plan[i];
    
    // 여행 계획 도시 모두 같은 집합인지 확인
    int root = find(plan[0]);
    bool possible = true;
    for (int i = 1; i < M; i++) {
        if (find(plan[i]) != root) { possible = false; break; }
    }
    
    cout << (possible ? "YES" : "NO") << "\n";
    return 0;
}