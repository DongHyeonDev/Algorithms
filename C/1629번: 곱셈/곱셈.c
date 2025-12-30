/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1629                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1629                           #+#        #+#      #+#    */
/*   Solved: 2025/12/30 12:18:00 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

// 분할 정복을 이용한 거듭제곱
long long power(long long A, long long B, long long C) {
    if (B == 0) {
        return 1;
    }

    long long half = power(A, B / 2, C);
    half = (half * half) % C;

    if (B % 2 == 1) {
        half = (half * A) % C;
    }

    return half;
}

int main() {
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);

    printf("%lld\n", power(A, B, C));

    return 0;
}