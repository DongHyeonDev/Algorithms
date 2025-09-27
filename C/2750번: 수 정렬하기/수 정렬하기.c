/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2750                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2750                           #+#        #+#      #+#    */
/*   Solved: 2025/09/27 16:03:18 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int arr[N];
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &arr[i]) != 1) return 0;
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}