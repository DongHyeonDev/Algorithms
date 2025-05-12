/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10811                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10811                          #+#        #+#      #+#    */
/*   Solved: 2025/05/12 23:10:23 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int basket[101];
    for (int i = 1; i <= N; i++) {
        basket[i] = i;
    }

    for (int cmd = 0; cmd < M; cmd++) {
        int i, j;
        scanf("%d %d", &i, &j);
        // i…j 구간 전체를 뒤집도록 l, r로 양끝부터 스왑
        for (int l = i, r = j; l < r; l++, r--) {
           int tmp = basket[l];
           basket[l] = basket[r];
           basket[r] = tmp;
        }
    }

    for (int i = 1; i <= N; i++) {
        printf("%d ", basket[i]);
    }
    printf("\n");
    return 0;
}