/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15651                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15651                          #+#        #+#      #+#    */
/*   Solved: 2025/11/24 14:53:17 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int N, M;
int sequence[7];

void backtrack(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            if (i > 0) printf(" ");
            printf("%d", sequence[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; i++) {
        sequence[depth] = i;

        backtrack(depth + 1);
    }
}

int main() {
    scanf("%d %d", &N, &M);

    backtrack(0);

    return 0;
}