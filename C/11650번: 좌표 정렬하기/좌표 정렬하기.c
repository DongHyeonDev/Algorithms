/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11650                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11650                          #+#        #+#      #+#    */
/*   Solved: 2025/10/01 00:15:05 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *point_a = (int *)a;
    int *point_b = (int *)b;

    if (point_a[0] != point_b[0]) {
        return point_a[0] - point_b[0];
    } else {
        return point_a[1] - point_b[1];
    }
}

int main() {
    int n;
    int arr[100000][2];

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%d %d", &arr[i][0], &arr[i][1]) != 2) return 0;
    }

    qsort(arr, n, sizeof(arr[0]), compare);

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }

    return 0;
}