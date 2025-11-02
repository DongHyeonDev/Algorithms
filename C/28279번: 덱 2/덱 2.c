/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 28279                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/28279                          #+#        #+#      #+#    */
/*   Solved: 2025/11/02 17:17:44 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#define MAX 2000005
int dq[MAX];
int head = 0, tail = 0;

int is_empty() {
    return head == tail;
}

int size() {
    return (tail - head + MAX) % MAX;
}

void push_front(int x) {
    head = (head - 1 + MAX) % MAX;
    dq[head] = x;
}

void push_back(int x) {
    dq[tail] = x;
    tail = (tail + 1) % MAX;
}

int pop_front() {
    if (is_empty()) return -1;
    int x = dq[head]; head = (head + 1) % MAX; return x;
}

int pop_back() {
    if (is_empty()) return -1;
    tail = (tail - 1 + MAX) % MAX; return dq[tail];
}

int front_val() {
    return is_empty() ? -1 : dq[head];
}

int back_val() {
    return is_empty() ? -1 : dq[(tail - 1 + MAX) % MAX];
}

int main() {
    int N, cmd, x;
    if (scanf("%d", &N) != 1) return 0;
    while (N--) {
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d", &x);
            push_front(x);
        } else if (cmd == 2) {
            scanf("%d", &x);
            push_back(x);
        } else if (cmd == 3) {
            printf("%d\n", pop_front());
        } else if (cmd == 4) {
            printf("%d\n", pop_back());
        } else if (cmd == 5) {
            printf("%d\n", size());
        } else if (cmd == 6) {
            printf("%d\n", is_empty() ? 1 : 0);
        } else if (cmd == 7) {
            printf("%d\n", front_val());
        } else {
            printf("%d\n", back_val());
        }
    }
    return 0;
}