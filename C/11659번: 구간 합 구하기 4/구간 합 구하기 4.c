/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11659                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11659                          #+#        #+#      #+#    */
/*   Solved: 2025/12/16 15:18:45 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int arr[100001];
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    // 누적 합 계산
    // prefix[i] = arr[1] + arr[2] + ... + arr[i]
    int prefix[100001] = {0};
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }

    // 쿼리 처리
    for (int q = 0; q < M; q++) {
        int i, j;
        scanf("%d %d", &i, &j);

        // 구간 [i, j]의 합 = prefix[j] - prefix[i-1]
        int sum = prefix[j] - prefix[i-1];
        printf("%d\n", sum);
    }

    return 0;
}