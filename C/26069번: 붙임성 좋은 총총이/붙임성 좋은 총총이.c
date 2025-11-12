/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 26069                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/26069                          #+#        #+#      #+#    */
/*   Solved: 2025/11/12 15:55:12 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_N 1000
#define MAX_LEN 21

int main() {
    int n;
    scanf("%d", &n);

    char dancers[MAX_N * 2][MAX_LEN];
    int dancer_count = 0;

    strcpy(dancers[dancer_count], "ChongChong");
    dancer_count++;

    for (int i = 0; i < n; i++) {
        char a[MAX_LEN], b[MAX_LEN];
        scanf("%s %s", a, b);

        int a_dancing = 0;
        for (int j = 0; j < dancer_count; j++) {
            if (strcmp(dancers[j], a) == 0) {
                a_dancing = 1;
                break;
            }
        }

        int b_dancing = 0;
        for (int j = 0; j < dancer_count; j++) {
            if (strcmp(dancers[j], b) == 0) {
                b_dancing = 1;
                break;
            }
        }

        if (a_dancing || b_dancing) {
            if (!a_dancing) {
                strcpy(dancers[dancer_count], a);
                dancer_count++;
            }
            if (!b_dancing) {
                strcpy(dancers[dancer_count], b);
                dancer_count++;
            }
        }
    }

    printf("%d\n", dancer_count);

    return 0;
}