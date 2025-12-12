/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11054                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11054                          #+#        #+#      #+#    */
/*   Solved: 2025/12/12 13:59:08 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N;
    scanf("%d", &N);

    int A[1000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // increase[i] = i로 끝나는 증가 부분 수열의 길이 (LIS)
    int increase[1000];
    for (int i = 0; i < N; i++) {
        increase[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                increase[i] = max(increase[i], increase[j] + 1);
            }
        }
    }

    // decrease[i] = i에서 시작하는 감소 부분 수열의 길이 (LDS)
    int decrease[1000];
    for (int i = N - 1; i >= 0; i--) {
        decrease[i] = 1;
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j]) {
                decrease[i] = max(decrease[i], decrease[j] + 1);
            }
        }
    }

    // 바이토닉 수열의 최대 길이
    // i를 정점으로 하는 바이토닉: increase[i] + decrease[i] - 1
    int result = 0;
    for (int i = 0; i < N; i++) {
        int bitonic = increase[i] + decrease[i] - 1;
        result = max(result, bitonic);
    }

    printf("%d\n", result);

    return 0;
}