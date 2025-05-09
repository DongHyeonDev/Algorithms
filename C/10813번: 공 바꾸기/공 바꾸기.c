/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10813                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10813                          #+#        #+#      #+#    */
/*   Solved: 2025/05/09 21:57:37 by dhkim0206     ###          ###   ##.kr    */
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
        int tmp = basket[i];
        basket[i] = basket[j];
        basket[j] = tmp;
    }

    for (int i = 1; i <= N; i++) {
        printf("%d ", basket[i]);
    }
    printf("\n");
    return 0;
}
