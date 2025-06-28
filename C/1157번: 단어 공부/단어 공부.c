/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1157                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1157                           #+#        #+#      #+#    */
/*   Solved: 2025/06/28 19:41:22 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int main() {
    char S[1000001];
    scanf("%1000000s", S);

    int freq[26] = {0};
    for (int i = 0; S[i]; i++) {
        char c = S[i];
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        }
        freq[c - 'A']++;
    }

    int max = 0, idx = -1;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > max) {
            max = freq[i];
            idx = i;
        }
    }

    int count_max = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == max) {
            count_max++;
        }
    }

    if (count_max > 1) {
        printf("?\n");
    } else {
        printf("%c\n", 'A' + idx);
    }
    return 0;
}