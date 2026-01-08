/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1300                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1300                           #+#        #+#      #+#    */
/*   Solved: 2026/01/08 16:43:47 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

using namespace std;

long long N, K;

// x 이하인 수의 개수
long long count_less_equal(long long x) {
    long long count = 0;

    for (long long i = 1; i <= N; i++) {
        // i번째 행에서 x 이하인 수의 개수
        // i * j <= x → j <= x / i
        long long cnt = min(x / i, N);
        count += cnt;
    }

    return count;
}

int main() {
    cin >> N >> K;

    // 이분 탐색
    long long left = 1;
    long long right = N * N;
    long long result = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long count = count_less_equal(mid);

        if (count >= K) {
            // mid 이하인 수가 K개 이상
            result = mid;
            right = mid - 1;
        } else {
            // mid 이하인 수가 K개 미만
            left = mid + 1;
        }
    }

    cout << result << "\n";

    return 0;
}