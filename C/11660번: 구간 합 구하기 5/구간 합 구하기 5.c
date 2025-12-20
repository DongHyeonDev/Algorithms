/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11660                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11660                          #+#        #+#      #+#    */
/*   Solved: 2025/12/20 20:35:07 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // 누적 합 배열 (1-indexed)
    static long long prefix[1025][1025];

    // 명시적 초기화
    memset(prefix, 0, sizeof(prefix));

    // 배열 입력 및 누적 합 계산
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int value;
            scanf("%d", &value);
            prefix[i][j] = (long long)value 
                         + prefix[i-1][j] 
                         + prefix[i][j-1] 
                         - prefix[i-1][j-1];
        }
    }

    // 쿼리 처리
    for (int q = 0; q < M; q++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        long long result = prefix[x2][y2] 
                         - prefix[x1-1][y2] 
                         - prefix[x2][y1-1] 
                         + prefix[x1-1][y1-1];

        printf("%lld\n", result);
    }

    return 0;
}