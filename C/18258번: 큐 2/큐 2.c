/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 18258                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/18258                          #+#        #+#      #+#    */
/*   Solved: 2025/10/30 14:41:29 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX 2000005
int q[MAX], h = 0, t = 0;

int main() {
    int N, x;
    char cmd[8];
    if (scanf("%d", &N) != 1) return 0;
    while (N--) {
        scanf("%s", cmd);
        if (cmd[0] == 'p' && cmd[1] == 'u') {
            scanf("%d", &x);
            q[t++] = x;
        } else if (cmd[0] == 'p') {
            if (h == t) puts("-1");
            else printf("%d\n", q[h++]);
        } else if (cmd[0] == 's') {
            printf("%d\n", t - h);
        } else if (cmd[0] == 'e') {
            printf("%d\n", h == t);
        } else if (cmd[0] == 'f') {
            if (h == t) puts("-1");
            else printf("%d\n", q[h]);
        } else {
            if (h == t) puts("-1");
            else printf("%d\n", q[t - 1]);
        }
    }
    return 0;
}