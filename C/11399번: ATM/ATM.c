/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11399                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11399                          #+#        #+#      #+#    */
/*   Solved: 2025/12/24 19:28:08 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

// 비교 함수 (오름차순)
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int N;
    scanf("%d", &N);

    int time[1000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &time[i]);
    }

    // 오름차순 정렬
    qsort(time, N, sizeof(int), compare);

    int total = 0;
    int cumulative = 0;

    for (int i = 0; i < N; i++) {
        cumulative += time[i];  // 누적 시간
        total += cumulative;     // 각 사람의 대기+처리 시간 합산
    }

    printf("%d\n", total);

    return 0;
}