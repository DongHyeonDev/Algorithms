/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10814                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10814                          #+#        #+#      #+#    */
/*   Solved: 2025/10/06 11:37:26 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age;
    int idx;
    char name[101];
} Member;

int cmp(const void* p, const void* q) {
    const Member* a = (const Member*)p;
    const Member* b = (const Member*)q;
    if (a->age != b->age) return (a->age < b->age) ? -1 : 1;
    return (a->idx < b->idx) ? -1 : 1;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    Member *arr = (Member*)malloc(sizeof(Member) * N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %100s", &arr[i].age, arr[i].name);
        arr[i].idx = i;
    }

    qsort(arr, N, sizeof(Member), cmp);

    for (int i = 0; i < N; ++i) {
        printf("%d %s\n", arr[i].age, arr[i].name);
    }

    free(arr);
    return 0;
}