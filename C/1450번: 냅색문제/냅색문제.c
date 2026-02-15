/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1450                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1450                           #+#        #+#      #+#    */
/*   Solved: 2026/02/15 19:43:44 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int weights[30];
int N, C;
long long left_sums[1 << 15];
long long right_sums[1 << 15];
int left_cnt, right_cnt;

int compare(const void* a, const void* b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

void make_sums(int start, int end, long long sums[], int* cnt) {
    int size = end - start;
    *cnt = 0;
    
    for (int mask = 0; mask < (1 << size); mask++) {
        long long sum = 0;
        for (int i = 0; i < size; i++) {
            if (mask & (1 << i)) {
                sum += weights[start + i];
            }
        }
        sums[(*cnt)++] = sum;
    }
}

long long upper_bound(long long arr[], int size, long long value) {
    int left = 0;
    int right = size;
    
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

int main() {
    scanf("%d %d", &N, &C);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &weights[i]);
    }
    
    int mid = N / 2;
    
    // 왼쪽 절반의 모든 부분집합 합
    make_sums(0, mid, left_sums, &left_cnt);
    
    // 오른쪽 절반의 모든 부분집합 합
    make_sums(mid, N, right_sums, &right_cnt);
    
    // 오른쪽 정렬
    qsort(right_sums, right_cnt, sizeof(long long), compare);
    
    long long count = 0;
    
    // 왼쪽 각 합에 대해 오른쪽에서 가능한 개수 찾기
    for (int i = 0; i < left_cnt; i++) {
        long long remain = C - left_sums[i];
        if (remain >= 0) {
            count += upper_bound(right_sums, right_cnt, remain);
        }
    }
    
    printf("%lld\n", count);
    
    return 0;
}