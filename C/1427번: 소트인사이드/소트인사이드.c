/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1427                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1427                           #+#        #+#      #+#    */
/*   Solved: 2025/10/03 22:21:05 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(char *)b - *(char *)a);
}

int main() {
    char str[11];

    if (scanf("%10s", str) != 1) return 0;

    qsort(str, strlen(str), sizeof(char), compare);
    printf("%s\n", str);

    return 0;
}