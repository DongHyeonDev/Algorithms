/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10798                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10798                          #+#        #+#      #+#    */
/*   Solved: 2025/07/17 19:40:12 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int main() {
    char S[5][16];
    int max_length = 0;

    for (int i = 0; i < 5; i++) {
        scanf("%s", S[i]);
        int length = strlen(S[i]);
        if (length > max_length) {
            max_length = length;
        }
    }

    for (int j = 0; j < max_length; j++) {
        for (int i = 0; i < 5; i++) {
            if (j < strlen(S[i])) {
                putchar(S[i][j]);
            }
        }
    }
    
    putchar('\n');
    return 0;
}