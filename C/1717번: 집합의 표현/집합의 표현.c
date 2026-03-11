/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1717                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1717                           #+#        #+#      #+#    */
/*   Solved: 2026/03/11 13:45:27 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#define MAX_N 1000001

int parent[MAX_N], rnk[MAX_N];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra == rb) return;
    if (rnk[ra] < rnk[rb])      parent[ra] = rb;
    else if (rnk[ra] > rnk[rb]) parent[rb] = ra;
    else { parent[rb] = ra; rnk[ra]++; }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i <= n; i++) parent[i] = i;
    
    for (int i = 0; i < m; i++) {
        int op, a, b;
        scanf("%d %d %d", &op, &a, &b);
        if (op == 0) unite(a, b);
        else         puts(find(a) == find(b) ? "YES" : "NO");
    }
    
    return 0;
}