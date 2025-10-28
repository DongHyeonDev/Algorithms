/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4949                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4949                           #+#        #+#      #+#    */
/*   Solved: 2025/10/28 14:48:35 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int main() {
    char line[101];
    while (1) {
        if (fgets(line, sizeof(line), stdin) == NULL) break;
        if (strcmp(line, ".\n") == 0) break;

        int len = strlen(line);
        char stk[101];
        int top = 0;
        int isValid = 1;

        for (int i = 0; i < len; i++) {
            if (line[i] == '(' || line[i] == '[') {
                stk[top++] = line[i];
            } else if (line[i] == ')') {
                if (top == 0 || stk[top - 1] != '(') {
                    isValid = 0;
                    break;
                }
                top--;
            } else if (line[i] == ']') {
                if (top == 0 || stk[top - 1] != '[') {
                    isValid = 0;
                    break;
                }
                top--;
            }
        }

        if (isValid && top == 0) {
            puts("yes");
        } else {
            puts("no");
        }
    }
    return 0;
}