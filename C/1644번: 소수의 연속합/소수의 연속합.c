/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1644                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1644                           #+#        #+#      #+#    */
/*   Solved: 2026/02/14 13:17:31 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <math.h>

int is_prime[4000001];
int primes[283146];  // N=4,000,000일 때 소수 개수 약 283,146개
int prime_count = 0;

void sieve(int N) {
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    
    int limit = (int)sqrt(N);
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    
    // 소수 목록 생성
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            primes[prime_count++] = i;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    // 에라토스테네스의 체
    sieve(N);
    
    // 투 포인터
    int left = 0;
    int right = 0;
    int sum = 0;
    int count = 0;
    
    while (1) {
        if (sum >= N) {
            if (sum == N) {
                count++;
            }
            sum -= primes[left];
            left++;
        } else if (right == prime_count) {
            break;
        } else {
            sum += primes[right];
            right++;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}