/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 28065                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/28065                          #+#        #+#      #+#    */
/*   Solved: 2026/04/02 13:20:23 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int N; scanf("%d", &N);
    int lo = 1, hi = N;
    int first = 1;
    while (lo <= hi) {
        if (!first) printf(" ");
        printf("%d", hi--); first = 0;
        if (lo <= hi) { printf(" %d", lo++); }
    }
    printf("\n");
    return 0;
}