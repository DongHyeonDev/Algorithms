/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2798                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2798                           #+#        #+#      #+#    */
/*   Solved: 2025/09/21 19:41:15 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;

    int a[100];
    for (int i = 0; i < N; ++i) scanf("%d", &a[i]);

    int best = 0;
    for (int i = 0; i < N - 2; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            for (int k = j + 1; k < N; ++k) {
                int sum = a[i] + a[j] + a[k];
                if (sum <= M && sum > best) best = sum;
            }
        }
    }

    printf("%d\n", best);
    return 0;
}