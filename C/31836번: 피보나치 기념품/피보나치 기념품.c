/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 31836                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/31836                          #+#        #+#      #+#    */
/*   Solved: 2026/04/08 14:27:13 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[2001], B[2001];
    int X = 0, Y = 0;

    if (N % 3 == 0) {
        for (int i = 1; i <= N; i++) {
            if (i % 3 == 0) B[Y++] = i;
            else A[X++] = i;
        }
    } else if (N % 3 == 2) {
        for (int i = 1; i <= N; i++) {
            if (i % 3 == 2) B[Y++] = i;
            else A[X++] = i;
        }
    } else { // N % 3 == 1
        for (int i = 1; i < N; i++) {
            if (i % 3 == 0) B[Y++] = i;
            else A[X++] = i;
        }
    }

    printf("%d\n", X);
    for (int i = 0; i < X; i++) {
        if (i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");

    printf("%d\n", Y);
    for (int i = 0; i < Y; i++) {
        if (i) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");

    return 0;
}