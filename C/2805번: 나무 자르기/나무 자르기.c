/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2805                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2805                           #+#        #+#      #+#    */
/*   Solved: 2026/01/06 17:34:40 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

long long trees[1000000];
int N;
long long M;

// 높이 h로 잘랐을 때 얻을 수 있는 나무 길이
long long get_wood(long long h) {
    long long total = 0;
    for (int i = 0; i < N; i++) {
        if (trees[i] > h) {
            total += trees[i] - h;
        }
    }
    return total;
}

int main() {
    scanf("%d %lld", &N, &M);

    long long max_height = 0;
    for (int i = 0; i < N; i++) {
        scanf("%lld", &trees[i]);
        if (trees[i] > max_height) {
            max_height = trees[i];
        }
    }

    // 이분 탐색
    long long left = 0;
    long long right = max_height;
    long long result = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long wood = get_wood(mid);

        if (wood >= M) {
            // M 이상 얻을 수 있으면 높이를 올려봄
            result = mid;
            left = mid + 1;
        } else {
            // M 미만이면 높이를 낮춤
            right = mid - 1;
        }
    }

    printf("%lld\n", result);

    return 0;
}