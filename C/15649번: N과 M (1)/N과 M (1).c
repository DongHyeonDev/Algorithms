/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15649                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15649                          #+#        #+#      #+#    */
/*   Solved: 2025/11/22 16:21:16 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int N, M;
int sequence[8];
int visited[9];

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
        if (visited[i]) continue;

        sequence[depth] = i;
        visited[i] = 1;

        backtrack(depth + 1);

        visited[i] = 0;
    }
}

int main() {
    scanf("%d %d", &N, &M);

    backtrack(0);

    return 0;
}