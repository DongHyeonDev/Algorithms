/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1931                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1931                           #+#        #+#      #+#    */
/*   Solved: 2025/12/23 13:25:54 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

// 비교 함수: 종료 시간 우선, 같으면 시작 시간 우선
int compare(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;

    if (m1->end != m2->end) {
        return m1->end - m2->end;  // 종료 시간 오름차순
    }
    return m1->start - m2->start;  // 시작 시간 오름차순
}

int main() {
    int N;
    scanf("%d", &N);

    Meeting meetings[100000];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    // 정렬
    qsort(meetings, N, sizeof(Meeting), compare);

    int count = 0;
    int last_end = 0;

    for (int i = 0; i < N; i++) {
        // 이전 회의가 끝난 시간 이후에 시작하는 회의 선택
        if (meetings[i].start >= last_end) {
            count++;
            last_end = meetings[i].end;
        }
    }

    printf("%d\n", count);

    return 0;
}