/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12865                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12865                          #+#        #+#      #+#    */
/*   Solved: 2025/12/15 10:41:11 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int weight[101], value[101];
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &weight[i], &value[i]);
    }

    // dp[w] = 무게 w 이하로 얻을 수 있는 최대 가치
    int dp[100001] = {0};

    // 각 물건을 고려
    for (int i = 1; i <= N; i++) {
        // 뒤에서부터 갱신 (같은 물건을 여러 번 선택하지 않도록)
        for (int w = K; w >= weight[i]; w--) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }

    printf("%d\n", dp[K]);

    return 0;
}