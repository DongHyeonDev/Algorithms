/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2108                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2108                           #+#        #+#      #+#    */
/*   Solved: 2025/11/13 13:43:52 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VAL 4000

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    long long sum = 0;

    int freq[MAX_VAL * 2 + 1] = {0};
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        freq[arr[i] + MAX_VAL]++;
    }

    double avg = (double)sum / n;
    int mean = (int)round(avg);
    printf("%d\n", mean);

    qsort(arr, n, sizeof(int), compare);
    printf("%d\n", arr[n / 2]);

    int max_freq = 0;
    int mode_count = 0;

    for (int i = 0; i <= MAX_VAL * 2; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
        }
    }

    int modes[2];
    int mode_idx = 0;
    for (int i = 0; i <= MAX_VAL * 2 && mode_idx < 2; i++) {
        if (freq[i] == max_freq) {
            modes[mode_idx++] = i - MAX_VAL;
        }
    }

    if (mode_idx > 1) {
        printf("%d\n", modes[1]);
    } else {
        printf("%d\n", modes[0]);
    }

    printf("%d\n", arr[n - 1] - arr[0]);

    free(arr);
    return 0;
}