/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12015                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12015                          #+#        #+#      #+#    */
/*   Solved: 2026/01/09 19:23:21 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int N;
int arr[1000000];
int lis[1000000];
int lis_len = 0;

// lower_bound: target 이상인 첫 번째 위치
int lower_bound(int target) {
    int left = 0, right = lis_len;

    while (left < right) {
        int mid = (left + right) / 2;
        if (lis[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N; i++) {
        int pos = lower_bound(arr[i]);

        lis[pos] = arr[i];

        if (pos == lis_len) {
            lis_len++;
        }
    }

    printf("%d\n", lis_len);

    return 0;
}