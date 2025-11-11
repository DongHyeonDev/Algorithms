/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25192                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25192                          #+#        #+#      #+#    */
/*   Solved: 2025/11/11 12:03:12 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_N 100000
#define MAX_LEN 21

int main() {
    int n;
    scanf("%d", &n);

    char users[MAX_N][MAX_LEN];
    int user_count = 0;
    int gomgom_count = 0;

    for (int i = 0; i < n; i++) {
        char input[MAX_LEN];
        scanf("%s", input);

        if (strcmp(input, "ENTER") == 0) {
            user_count = 0;
        } else {
            int is_first = 1;
            for (int j = 0; j < user_count; j++) {
                if (strcmp(users[j], input) == 0) {
                    is_first = 0;
                    break;
                }
            }

            if (is_first) {
                gomgom_count++;
                strcpy(users[user_count], input);
                user_count++;
            }
        }
    }

    printf("%d\n", gomgom_count);

    return 0;
}