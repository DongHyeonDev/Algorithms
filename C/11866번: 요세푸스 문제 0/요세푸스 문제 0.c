/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11866                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11866                          #+#        #+#      #+#    */
/*   Solved: 2025/11/01 13:44:16 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#define CAP 1005
int q[CAP], head = 0, sz = 0;

void push(int x) {
    q[(head + sz) % CAP] = x;
    sz++;
}

int pop() {
    int x = q[head];
    head = (head + 1) % CAP;
    sz--;
    return x;
}

int empty() {
    return sz == 0;
}

int main() {
    int N, K; 
    if (scanf("%d %d", &N, &K) != 2) return 0;

    for (int i = 1; i <= N; i++) push(i);

    printf("<");
    for (int i = 0; i < N; i++) {
        for (int t = 0; t < K - 1; t++) push(pop());
        int x = pop();
        if (i == N - 1) printf("%d>", x);
        else printf("%d, ", x);
    }
    return 0;
}