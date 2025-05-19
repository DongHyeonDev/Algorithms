/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9086                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9086                           #+#        #+#      #+#    */
/*   Solved: 2025/05/19 23:24:57 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        char S[1001];
        scanf("%s", S);
        
        int length = strlen(S);
        printf("%c%c\n", S[0], S[length - 1]);
    }
    
    return 0;
}