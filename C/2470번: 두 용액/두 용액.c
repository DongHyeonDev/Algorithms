/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2470                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2470                           #+#        #+#      #+#    */
/*   Solved: 2026/02/12 12:10:27 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

long long abs_ll(long long x) {
    return x < 0 ? -x : x;
}

int main() {
    int n;
    int arr[100000];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // 정렬
    qsort(arr, n, sizeof(int), compare);
    
    // 투 포인터
    int left = 0;
    int right = n - 1;
    long long min_diff = 2000000001LL;
    int result_left = 0;
    int result_right = 0;
    
    while (left < right) {
        long long sum = (long long)arr[left] + arr[right];
        long long diff = abs_ll(sum);
        
        if (diff < min_diff) {
            min_diff = diff;
            result_left = arr[left];
            result_right = arr[right];
        }
        
        if (sum == 0) {
            break;
        } else if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }
    
    printf("%d %d\n", result_left, result_right);
    
    return 0;
}