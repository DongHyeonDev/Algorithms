/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4195                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4195                           #+#        #+#      #+#    */
/*   Solved: 2026/03/13 16:49:01 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_F  200001  // 최대 2*F명
#define MAX_LEN 21

// 간단한 해시맵 (체이닝)
typedef struct Node {
    char key[MAX_LEN];
    int  val;
    struct Node* next;
} Node;

#define HASH_SIZE 400003
Node* hashTable[HASH_SIZE];
int   parent[MAX_F], sz[MAX_F];
int   nextId;

int hashKey(const char* s) {
    unsigned int h = 5381;
    while (*s) h = h * 33 + (unsigned char)(*s++);
    return h % HASH_SIZE;
}

int getId(const char* name) {
    int h = hashKey(name);
    for (Node* n = hashTable[h]; n; n = n->next)
        if (strcmp(n->key, name) == 0) return n->val;
    // 새 ID 등록
    Node* n = malloc(sizeof(Node));
    strcpy(n->key, name); n->val = nextId;
    n->next = hashTable[h]; hashTable[h] = n;
    parent[nextId] = nextId; sz[nextId] = 1;
    return nextId++;
}

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

int unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra == rb) return sz[ra];
    if (sz[ra] < sz[rb]) { parent[ra] = rb; sz[rb] += sz[ra]; return sz[rb]; }
    else                  { parent[rb] = ra; sz[ra] += sz[rb]; return sz[ra]; }
}

void clearHash() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* cur = hashTable[i];
        while (cur) { Node* nx = cur->next; free(cur); cur = nx; }
        hashTable[i] = NULL;
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int F; scanf("%d", &F);
        clearHash(); nextId = 0;
        
        for (int i = 0; i < F; i++) {
            char a[MAX_LEN], b[MAX_LEN];
            scanf("%s %s", a, b);
            printf("%d\n", unite(getId(a), getId(b)));
        }
    }
    return 0;
}