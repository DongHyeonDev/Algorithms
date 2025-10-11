/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1620                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1620                           #+#        #+#      #+#    */
/*   Solved: 2025/10/11 12:38:50 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[21];
    int idx;
} Node;

int cmpNode(const void* a, const void* b) {
    const Node* x = (const Node*)a;
    const Node* y = (const Node*)b;
    return strcmp(x->name, y->name);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    char (*nameByIdx)[21] = malloc((n + 1) * 21);
    Node* byName = (Node*)malloc(sizeof(Node) * n);
    if (!nameByIdx || !byName) return 0;

    for (int i = 1; i <= n; ++i) {
        scanf("%20s", nameByIdx[i]);
        strcpy(byName[i - 1].name, nameByIdx[i]);
        byName[i - 1].idx = i;
    }

    qsort(byName, n, sizeof(Node), cmpNode);

    char q[21];
    while (m--) {
        if (scanf("%20s", q) != 1) break;
        if (isdigit((unsigned char)q[0])) {
            int k = atoi(q);
            puts(nameByIdx[k]);
        } else {
            Node key;
            strcpy(key.name, q);
            Node* res = bsearch(&key, byName, n, sizeof(Node), cmpNode);
            printf("%d\n", res->idx);
        }
    }

    free(byName);
    free(nameByIdx);
    return 0;
}