/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2559                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2559                           #+#        #+#      #+#    */
/*   Solved: 2025/12/17 12:50:14 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int temp[100000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp[i]);
    }

    // 처음 K개의 합
    int current_sum = 0;
    for (int i = 0; i < K; i++) {
        current_sum += temp[i];
    }

    int max_sum = current_sum;

    // 슬라이딩 윈도우
    for (int i = K; i < N; i++) {
        // 왼쪽 원소 제거, 오른쪽 원소 추가
        current_sum = current_sum - temp[i-K] + temp[i];
        max_sum = max(max_sum, current_sum);
    }

    printf("%d\n", max_sum);

    return 0;
}