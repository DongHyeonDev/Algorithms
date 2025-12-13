/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2565                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2565                           #+#        #+#      #+#    */
/*   Solved: 2025/12/13 03:47:54 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} Wire;

int compare(const void *x, const void *y) {
    Wire *w1 = (Wire*)x;
    Wire *w2 = (Wire*)y;
    return w1->a - w2->a;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N;
    scanf("%d", &N);

    Wire wires[100];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &wires[i].a, &wires[i].b);
    }

    // A 위치 기준으로 정렬
    qsort(wires, N, sizeof(Wire), compare);

    // B 위치에서 LIS 찾기
    int dp[100];
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (wires[j].b < wires[i].b) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // LIS의 최대 길이 찾기
    int lis_length = 0;
    for (int i = 0; i < N; i++) {
        lis_length = max(lis_length, dp[i]);
    }

    // 제거해야 할 전깃줄의 개수
    int result = N - lis_length;

    printf("%d\n", result);

    return 0;
}