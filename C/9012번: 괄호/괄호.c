/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9012                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9012                           #+#        #+#      #+#    */
/*   Solved: 2025/10/27 12:09:33 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int main() {
    int T;
    char str[51];
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        scanf("%s", str);
        int len = strlen(str);
        int balance = 0;
        int isValid = 1;

        for (int i = 0; i < len; i++) {
            if (str[i] == '(') {
                balance++;
            } else if (str[i] == ')') {
                balance--;
                if (balance < 0) {
                    isValid = 0;
                    break;
                }
            }
        }

        if (isValid && balance == 0) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}