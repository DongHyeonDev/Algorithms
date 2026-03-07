/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1991                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1991                           #+#        #+#      #+#    */
/*   Solved: 2026/03/07 11:25:52 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char left_child[26], right_child[26];
char pre[27], ino[27], post[27];
int pi = 0, ii = 0, poi = 0;

void traverse(char node) {
    if (node == '.') return;
    int idx = node - 'A';
    pre[pi++] = node;                     // 전위
    traverse(left_child[idx]);
    ino[ii++] = node;                     // 중위
    traverse(right_child[idx]);
    post[poi++] = node;                   // 후위
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        char node, l, r;
        scanf(" %c %c %c", &node, &l, &r);
        left_child[node - 'A']  = l;
        right_child[node - 'A'] = r;
    }
    
    traverse('A');
    
    pre[pi] = ino[ii] = post[poi] = '\0';
    printf("%s\n%s\n%s\n", pre, ino, post);
    
    return 0;
}