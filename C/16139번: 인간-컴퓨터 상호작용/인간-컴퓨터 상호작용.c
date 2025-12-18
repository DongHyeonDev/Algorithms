/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 16139                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/16139                          #+#        #+#      #+#    */
/*   Solved: 2025/12/18 13:17:01 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char S[200001];
    fgets(S, 200001, stdin);
    S[strcspn(S, "\n")] = 0;  // 개행문자 제거

    int len = strlen(S);

    // 2차원 배열 동적 할당
    int (*prefix)[200001] = calloc(26, sizeof(*prefix));

    // 누적 합 계산
    for (int j = 0; j < len; j++) {
        int ch = S[j] - 'a';
        for (int i = 0; i < 26; i++) {
            prefix[i][j + 1] = prefix[i][j] + (i == ch ? 1 : 0);
        }
    }

    int q;
    scanf("%d", &q);

    while (q--) {
        char alpha;
        int l, r;
        scanf(" %c %d %d", &alpha, &l, &r);

        int idx = alpha - 'a';
        printf("%d\n", prefix[idx][r + 1] - prefix[idx][l]);
    }

    free(prefix);
    return 0;
}