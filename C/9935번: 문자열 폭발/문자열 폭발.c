/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9935                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9935                           #+#        #+#      #+#    */
/*   Solved: 2026/04/18 16:17:14 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_S 1000001
#define MAX_B 37

char s[MAX_S], bomb[MAX_B];
char stk[MAX_S];
int matchLen[MAX_S];  // 해당 위치에서의 매칭 길이
int top = 0;

int main() {
    scanf("%s %s", s, bomb);
    int sLen = strlen(s), bLen = strlen(bomb);
    
    for (int i = 0; i < sLen; i++) {
        char ch = s[i];
        int cur = (top == 0) ? 0 : matchLen[top-1];
        
        int next;
        if (ch == bomb[cur]) {
            next = cur + 1;
        } else {
            next = (ch == bomb[0]) ? 1 : 0;
        }
        
        stk[top] = ch;
        matchLen[top] = next;
        top++;
        
        if (next == bLen) {
            top -= bLen;
        }
    }
    
    if (top == 0) {
        printf("FRULA\n");
    } else {
        stk[top] = '\0';
        printf("%s\n", stk);
    }
    return 0;
}