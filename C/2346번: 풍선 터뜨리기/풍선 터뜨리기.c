/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2346                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2346                           #+#        #+#      #+#    */
/*   Solved: 2025/11/03 14:12:38 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

typedef struct {
    int idx, mv;
} Node;

#define MAX 2005
Node dq[MAX];
int head = 0, tail = 0;
int MOD = MAX;

int empty() {
    return head == tail;
}

int size() {
    return (tail - head + MOD) % MOD;
}

void push_back(Node x) {
    dq[tail] = x;
    tail = (tail + 1) % MOD;
}

void push_front(Node x) {
    head = (head - 1 + MOD) % MOD;
    dq[head] = x;
}

Node pop_front() {
    Node x = dq[head];
    head = (head + 1) % MOD;
    return x;
}

Node pop_back() {
    tail = (tail - 1 + MOD) % MOD;
    return dq[tail];
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    for (int i = 1; i <= N; ++i) {
        int v;
        scanf("%d", &v);
        push_back((Node){i, v});
    }

    Node cur = pop_front();
    printf("%d", cur.idx);

    int k = cur.mv;
    while (!empty()) {
        if (k > 0) {
            for (int r = 0; r < k - 1; ++r) {
                push_back(pop_front());
            }
            cur = pop_front();
        } else {
            for (int r = 0; r < -k; ++r) {
                push_front(pop_back());
            }
            cur = pop_front();
        }
        printf(" %d", cur.idx);
        k = cur.mv;
    }
    printf("\n");
    return 0;
}