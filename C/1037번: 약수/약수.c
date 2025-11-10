/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1037                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1037                           #+#        #+#      #+#    */
/*   Solved: 2025/11/10 12:35:09 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int min = 1000001;
    int max = 0;

    for (int i = 0; i < n; i++) {
        int divisor;
        scanf("%d", &divisor);
        
        if (divisor < min) {
            min = divisor;
        }
        if (divisor > max) {
            max = divisor;
        }
    }

    long long N = (long long)min * max;

    printf("%lld\n", N);

    return 0;
}