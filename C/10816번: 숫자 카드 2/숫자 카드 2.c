/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10816                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10816                          #+#        #+#      #+#    */
/*   Solved: 2025/10/12 12:44:01 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void* a, const void* b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int lower_bound(const int* a, int n, int key) {
    int l = 0, r = n;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] >= key) r = m;
        else l = m + 1;
    }
    return l;
}

int upper_bound(const int* a, int n, int key) {
    int l = 0, r = n;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] > key) r = m;
        else l = m + 1;
    }
    return l;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), cmp_int);

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int q; scanf("%d", &q);
        int l = lower_bound(arr, n, q);
        int r = upper_bound(arr, n, q);
        int cnt = r - l;
        printf("%d%c", cnt, (i + 1 == m) ? '\n' : ' ');
    }

    free(arr);
    return 0;
}