/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10815                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10815                          #+#        #+#      #+#    */
/*   Solved: 2025/10/08 20:11:29 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int main() {
    int N; 
    if (scanf("%d", &N) != 1) return 0;

    int *cards = (int*)malloc(sizeof(int)*N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &cards[i]);
    }

    qsort(cards, N, sizeof(int), cmp_int);

    int M; 
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int x; 
        scanf("%d", &x);
        void *p = bsearch(&x, cards, N, sizeof(int), cmp_int);
        printf("%d%c", p ? 1 : 0, (i+1==M)?'\n':' ');
    }

    free(cards);
    return 0;
}