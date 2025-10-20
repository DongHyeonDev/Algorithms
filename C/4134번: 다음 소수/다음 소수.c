/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4134                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4134                           #+#        #+#      #+#    */
/*   Solved: 2025/10/20 11:24:43 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long isprime(long long n) {
    if (n <= 2) return 2;
    long long prime = n;

    for (long long i = 2; i <= sqrt(prime); i++) {
        if (prime % i == 0) {
            prime++;
            i = 1;
        }
    }

    return prime;
}

int main() {
    long long T, n;
    scanf("%lld", &T);

    for (int i = 0; i < T; i++) {
        scanf("%lld", &n);
        printf("%lld\n", isprime(n));
    }
    
    return 0;
}