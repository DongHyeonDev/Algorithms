/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15650                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15650                          #+#        #+#      #+#    */
/*   Solved: 2025/11/23 17:22:34 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int N, M;
int sequence[8];

void backtrack(int depth, int start) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            if (i > 0) printf(" ");
            printf("%d", sequence[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= N; i++) {
        sequence[depth] = i;

        backtrack(depth + 1, i + 1);
    }
}

int main() {
    scanf("%d %d", &N, &M);

    backtrack(0, 1);

    return 0;
}