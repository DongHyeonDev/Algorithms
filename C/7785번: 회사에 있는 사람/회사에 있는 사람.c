/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7785                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7785                           #+#        #+#      #+#    */
/*   Solved: 2025/10/10 11:39:03 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[6];
    int enter;
    int t;
} Rec;

int cmp_rec(const void* a, const void* b) {
    const Rec* x = (const Rec*)a; 
    const Rec* y = (const Rec*)b;
    int s = strcmp(x->name, y->name);
    if (s) return s;
    return (x->t > y->t) - (x->t < y->t);
}

int cmp_name_desc(const void* a, const void* b) {
    const char* x = *(const char* const*)a; // (미사용 버전)
    const char* y = *(const char* const*)b; // (미사용 버전)
    return 0;
}

int cmp_char6_desc(const void* a, const void* b) {
    return -strcmp((const char*)a, (const char*)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Rec* log = (Rec*)malloc(sizeof(Rec) * n);
    for (int i = 0; i < n; ++i) {
        char op[8];
        scanf("%5s %7s", log[i].name, op);
        log[i].enter = (op[0] == 'e'); // "enter"면 1
        log[i].t = i;
    }

    qsort(log, n, sizeof(Rec), cmp_rec);

    char (*ans)[6] = (char(*)[6])malloc(sizeof(char[6]) * n);
    int m = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j + 1 < n && strcmp(log[j+1].name, log[i].name) == 0) ++j;
        if (log[j].enter) strcpy(ans[m++], log[j].name);
        i = j + 1;
    }

    qsort(ans, m, sizeof(ans[0]), cmp_char6_desc);

    for (int i = 0; i < m; ++i) puts(ans[i]);

    free(ans);
    free(log);
    return 0;
}