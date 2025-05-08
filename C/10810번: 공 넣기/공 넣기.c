/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10810                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10810                          #+#        #+#      #+#    */
/*   Solved: 2025/05/08 22:51:42 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int basket[101] = {0};

    for (int cmd = 0; cmd < M; cmd++) {
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);
        for (int b = i; b <= j; b++) {
            basket[b] = k;
        }
    }

    for (int b = 1; b <= N; b++) {
        printf("%d ", basket[b]);
    }
    printf("\n");
    return 0;
}
