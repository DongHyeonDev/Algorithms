/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1316                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1316                           #+#        #+#      #+#    */
/*   Solved: 2025/07/03 12:17:23 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    int group_count = 0;
    char s[101];
    while (N--) {
        scanf("%s", s);

        int seen[26] = {0};
        char prev = 0;
        int is_group = 1;

        for (int i = 0; s[i]; i++) {
            char c = s[i];
            if (c != prev) {
                // 이전에 등장했으면 그룹 단어 아님
                if (seen[c - 'a']) {
                    is_group = 0;
                    break;
                }
                seen[c - 'a'] = 1;
                prev = c;
            }
        }

        if (is_group) {
            group_count++;
        }
    }

    printf("%d\n", group_count);
    return 0;
}