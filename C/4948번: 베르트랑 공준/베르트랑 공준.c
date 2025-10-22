/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4948                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4948                           #+#        #+#      #+#    */
/*   Solved: 2025/10/22 11:46:18 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#define MAX 246912
static char composite[MAX + 1];

int main() {
    composite[0] = composite[1] = 1;
    for (int p = 2; p * p <= MAX; ++p) {
        if (!composite[p]) {
            for (int q = p * p; q <= MAX; q += p) {
                composite[q] = 1;
            }
        }
    }

    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int cnt = 0;
        for (int x = n + 1; x <= 2 * n; ++x) {
            if (!composite[x]) ++cnt;
        }
        printf("%d\n", cnt);
    }
    return 0;
}