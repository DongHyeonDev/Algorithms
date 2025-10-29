/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12789                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12789                          #+#        #+#      #+#    */
/*   Solved: 2025/10/29 19:24:40 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#define MAX 1000001
int n, a[MAX], stk[MAX], top = 0, need = 1;

int main() {
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    for (int i = 0; i < n; ++i) {
        while (top > 0 && stk[top - 1] == need) { --top; ++need; }
        if (a[i] == need) ++need;
        else stk[top++] = a[i];
    }
    while (top > 0 && stk[top - 1] == need) { --top; ++need; }

    puts(top == 0 ? "Nice" : "Sad");
    return 0;
}