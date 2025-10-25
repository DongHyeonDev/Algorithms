/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 28278                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/28278                          #+#        #+#      #+#    */
/*   Solved: 2025/10/25 17:14:02 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#define MAX 1000000
int s[MAX], top = 0;

int main() {
    int n, cmd, x;
    if (scanf("%d", &n) != 1) return 0;
    
    while (n--) {
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d", &x);
            s[top++] = x;
        } else if (cmd == 2) {
            if (top == 0) puts("-1");
            else printf("%d\n", s[--top]);
        } else if (cmd == 3) {
            printf("%d\n", top);
        } else if (cmd == 4) {
            printf("%d\n", top == 0);
        } else if (cmd == 5) {
            if (top == 0) puts("-1");
            else printf("%d\n", s[top - 1]);
        }
    }
    return 0;
}