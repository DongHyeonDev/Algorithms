/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25288                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25288                          #+#        #+#      #+#    */
/*   Solved: 2026/04/06 13:26:01 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) { return *(char*)a - *(char*)b; }

int main() {
    int N; scanf("%d", &N);
    char s[27]; scanf("%s", s);
    int k = strlen(s);
    qsort(s, k, sizeof(char), cmp);
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < k; j++)
            putchar(s[j]);
    putchar('\n');
    return 0;
}