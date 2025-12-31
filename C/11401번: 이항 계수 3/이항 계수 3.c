/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11401                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11401                          #+#        #+#      #+#    */
/*   Solved: 2025/12/31 09:45:47 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#define MOD 1000000007
#define MAX 4000001

long long factorial[MAX];

// 분할 정복을 이용한 거듭제곱 (모듈러)
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

// 모듈러 곱셈 역원 (페르마의 소정리 이용)
long long mod_inverse(long long n, long long mod) {
    return power(n, mod - 2, mod);
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    // 팩토리얼 전처리
    factorial[0] = 1;
    for (int i = 1; i <= N; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }

    // C(N, K) = N! / (K! * (N-K)!)
    // = N! * (K!)^(-1) * ((N-K)!)^(-1) mod MOD
    long long numerator = factorial[N];
    long long denominator = (factorial[K] * factorial[N - K]) % MOD;

    long long result = (numerator * mod_inverse(denominator, MOD)) % MOD;

    printf("%lld\n", result);

    return 0;
}