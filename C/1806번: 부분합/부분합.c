/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1806                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1806                           #+#        #+#      #+#    */
/*   Solved: 2026/02/13 15:52:27 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int N, S;
    int arr[100000];
    
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    int left = 0;
    int right = 0;
    int sum = 0;
    int min_length = N + 1;
    
    while (1) {
        if (sum >= S) {
            // 조건 만족: 길이 갱신하고 left 증가
            min_length = min(min_length, right - left);
            sum -= arr[left];
            left++;
        } else if (right == N) {
            // 더 이상 확장 불가
            break;
        } else {
            // 합이 부족: right 증가
            sum += arr[right];
            right++;
        }
    }
    
    if (min_length == N + 1) {
        printf("0\n");
    } else {
        printf("%d\n", min_length);
    }
    
    return 0;
}