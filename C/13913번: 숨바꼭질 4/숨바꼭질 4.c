/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 13913                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/13913                          #+#        #+#      #+#    */
/*   Solved: 2026/02/28 12:59:19 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX 100001

int dist[MAX];
int from[MAX];
int queue[MAX * 3];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    memset(dist, -1, sizeof(dist));
    memset(from, -1, sizeof(from));
    
    int head = 0, tail = 0;
    dist[N] = 0;
    queue[tail++] = N;
    
    while (head < tail) {
        int x = queue[head++];
        if (x == K) break;
        
        int nexts[3] = {x - 1, x + 1, x * 2};
        for (int i = 0; i < 3; i++) {
            int nx = nexts[i];
            if (nx < 0 || nx >= MAX) continue;
            if (dist[nx] != -1) continue;
            dist[nx] = dist[x] + 1;
            from[nx] = x;
            queue[tail++] = nx;
        }
    }
    
    printf("%d\n", dist[K]);
    
    // 역추적
    int path[MAX], len = 0;
    int cur = K;
    while (cur != -1) {
        path[len++] = cur;
        cur = from[cur];
    }
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
    
    return 0;
}