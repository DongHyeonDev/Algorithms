/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 13909                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/13909                          #+#        #+#      #+#    */
/*   Solved: 2025/10/24 13:34:47 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <math.h>

int main() {
    long long N;
    if (scanf("%lld", &N) != 1) return 0;

    long long ans = (long long)floor(sqrt((long double)N));
    printf("%lld\n", ans);
    return 0;
}