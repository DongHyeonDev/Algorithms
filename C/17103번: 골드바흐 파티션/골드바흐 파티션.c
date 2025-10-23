/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17103                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17103                          #+#        #+#      #+#    */
/*   Solved: 2025/10/23 08:53:27 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#define MAXN 1000000

static char composite[MAXN + 1];

int main() {
    composite[0] = composite[1] = 1;
    for (int p = 2; p * p <= MAXN; ++p) {
        if (!composite[p]) {
            for (int q = p * p; q <= MAXN; q += p) {
                composite[q] = 1;
            }
        }
    }

    int T; 
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int N;
        scanf("%d", &N);

        int cnt = 0;
        for (int p = 2; p <= N / 2; ++p) {
            if (!composite[p] && !composite[N - p]) {
                ++cnt;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}