/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11005                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11005                          #+#        #+#      #+#    */
/*   Solved: 2025/07/24 18:35:36 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    long long N;
    int B;
    scanf("%lld %d", &N, &B);

    if (N == 0) {
        printf("0\n");
        return 0;
    }

    char buf[64];
    int idx = 0;

    while (N > 0) {
        int rem = N % B;
        if (rem < 10) {
            buf[idx++] = '0' + rem;
        } else {
            buf[idx++] = 'A' + (rem - 10);
        }
        N /= B;
    }

    for (int i = idx - 1; i >= 0; i--) {
        putchar(buf[i]);
    }
    putchar('\n');

    return 0;
}