/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 28279                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/28279                          #+#        #+#      #+#    */
/*   Solved: 2025/11/02 17:17:52 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

const int MAX = 2000005;
int dq[MAX];
int head=0, tail=0;

bool empty() {
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
    if (empty()) return -1;
    int x = dq[head];
    head = (head + 1) % MAX;
    return x;
}

int pop_back() {
    if (empty()) return -1;
    tail = (tail - 1 + MAX) % MAX;
    return dq[tail];
}

int front_val() {
    return empty() ? -1 : dq[head];
}

int back_val() {
    return empty() ? -1 : dq[(tail - 1 + MAX) % MAX];
}

int main() {
    int N, cmd, x;
    if (!(std::cin >> N)) return 0;
    while (N--) {
        std::cin >> cmd;
        if (cmd == 1) {
            std::cin >> x;
            push_front(x);
        } else if (cmd == 2) {
            std::cin >> x;
            push_back(x);
        } else if (cmd == 3) {
            std::cout << pop_front() << '\n';
        } else if (cmd == 4) {
            std::cout << pop_back() << '\n';
        } else if (cmd == 5) {
            std::cout << size() << '\n';
        } else if (cmd == 6) {
            std::cout << (empty() ? 1 : 0) << '\n';
        } else if (cmd == 7) {
            std::cout << front_val() << '\n';
        } else {
            std::cout << back_val() << '\n';
        }
    }
    return 0;
}