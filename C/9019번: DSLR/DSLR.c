/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9019                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9019                           #+#        #+#      #+#    */
/*   Solved: 2026/03/01 11:00:22 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX 10000

int dist[MAX], from[MAX];
char op[MAX];
int queue[MAX];

int applyD(int n) { return (n * 2) % 10000; }
int applyS(int n) { return n == 0 ? 9999 : n - 1; }
int applyL(int n) { return (n % 1000) * 10 + n / 1000; }
int applyR(int n) { return (n % 10) * 1000 + n / 10; }

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);
        
        memset(dist, -1, sizeof(dist));
        memset(from, -1, sizeof(from));
        
        int head = 0, tail = 0;
        dist[A] = 0;
        queue[tail++] = A;
        
        while (head < tail) {
            int x = queue[head++];
            if (x == B) break;
            
            int nexts[4] = {applyD(x), applyS(x), applyL(x), applyR(x)};
            char cmds[4] = {'D', 'S', 'L', 'R'};
            
            for (int i = 0; i < 4; i++) {
                int nx = nexts[i];
                if (dist[nx] != -1) continue;
                dist[nx] = dist[x] + 1;
                from[nx] = x;
                op[nx]   = cmds[i];
                queue[tail++] = nx;
            }
        }
        
        // 역추적
        char result[MAX];
        int len = 0, cur = B;
        while (cur != A) {
            result[len++] = op[cur];
            cur = from[cur];
        }
        // 역순 출력
        for (int i = len - 1; i >= 0; i--) printf("%c", result[i]);
        printf("\n");
    }
    
    return 0;
}