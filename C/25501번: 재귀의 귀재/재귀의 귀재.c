/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25501                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25501                          #+#        #+#      #+#    */
/*   Solved: 2025/11/17 10:25:08 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int call_count;

int recursion(const char *s, int l, int r) {
    call_count++;

    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char s[1001];
        scanf("%s", s);

        call_count = 0;
        int result = isPalindrome(s);

        printf("%d %d\n", result, call_count);
    }

    return 0;
}