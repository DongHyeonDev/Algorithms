/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 24416                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/24416                          #+#        #+#      #+#    */
/*   Solved: 2025/11/30 10:29:50 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

long long fib[41];

// 동적 프로그래밍으로 피보나치 수 계산
long long fibonacci(int n) {
    fib[1] = 1;
    fib[2] = 1;

    for (int i = 3; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    int n;
    scanf("%d", &n);

    // 코드1 실행 횟수 = fib(n)
    long long code1_count = fibonacci(n);

    // 코드2 실행 횟수 = n - 2
    int code2_count = n - 2;

    printf("%lld %d\n", code1_count, code2_count);

    return 0;
}