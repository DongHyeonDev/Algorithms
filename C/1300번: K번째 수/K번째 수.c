/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1300                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1300                           #+#        #+#      #+#    */
/*   Solved: 2026/01/08 16:43:41 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

long long N, K;

// x 이하인 수의 개수
long long count_less_equal(long long x) {
    long long count = 0;

    for (long long i = 1; i <= N; i++) {
        // i번째 행에서 x 이하인 수의 개수
        // i * j <= x → j <= x / i
        long long cnt = x / i;
        if (cnt > N) cnt = N;  // 최대 N개
        count += cnt;
    }

    return count;
}

int main() {
    scanf("%lld %lld", &N, &K);

    // 이분 탐색
    long long left = 1;
    long long right = N * N;
    long long result = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long count = count_less_equal(mid);

        if (count >= K) {
            // mid 이하인 수가 K개 이상
            // mid가 답이거나 더 작은 수가 답
            result = mid;
            right = mid - 1;
        } else {
            // mid 이하인 수가 K개 미만
            // 더 큰 수를 찾아야 함
            left = mid + 1;
        }
    }

    printf("%lld\n", result);

    return 0;
}