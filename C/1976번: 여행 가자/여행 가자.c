/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1976                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1976                           #+#        #+#      #+#    */
/*   Solved: 2026/03/12 17:14:34 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#define MAX_N 201

int parent[MAX_N];

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
    scanf("%d %d", &N, &M);
    
    for (int i = 1; i <= N; i++) parent[i] = i;
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            int conn; scanf("%d", &conn);
            if (conn) unite(i, j);
        }
    
    int plan[1001];
    for (int i = 0; i < M; i++) scanf("%d", &plan[i]);
    
    int root = find(plan[0]);
    int possible = 1;
    for (int i = 1; i < M; i++)
        if (find(plan[i]) != root) { possible = 0; break; }
    
    puts(possible ? "YES" : "NO");
    return 0;
}