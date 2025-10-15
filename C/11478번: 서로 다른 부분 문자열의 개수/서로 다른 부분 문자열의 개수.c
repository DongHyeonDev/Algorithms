/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11478                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11478                          #+#        #+#      #+#    */
/*   Solved: 2025/10/15 12:42:34 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1001

char *subs[500500];

int cmp(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    char s[MAX];
    scanf("%s", s);
    int len = strlen(s);

    int idx = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j <= len; j++) {
            int l = j - i;
            subs[idx] = (char *)malloc(l + 1);
            strncpy(subs[idx], s + i, l);
            subs[idx][l] = '\0';
            idx++;
        }
    }

    qsort(subs, idx, sizeof(char *), cmp);

    int count = 1;
    for (int i = 1; i < idx; i++) {
        if (strcmp(subs[i - 1], subs[i]) != 0) {
            count++;
        }
    }

    printf("%d\n", count);

    for (int i = 0; i < idx; i++) {
        free(subs[i]);
    }

    return 0;
}