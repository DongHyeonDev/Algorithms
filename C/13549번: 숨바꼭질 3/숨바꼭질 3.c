/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 13549                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/13549                          #+#        #+#      #+#    */
/*   Solved: 2026/02/06 16:10:44 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX 100001

int dist[MAX];
int deque[MAX * 2];
int front, rear;

void push_front(int x) {
    deque[--front] = x;
}

void push_back(int x) {
    deque[rear++] = x;
}

int pop_front() {
    return deque[front++];
}

int is_empty() {
    return front == rear;
}

int bfs(int N, int K) {
    memset(dist, -1, sizeof(dist));
    front = MAX;
    rear = MAX;
    
    dist[N] = 0;
    push_back(N);
    
    while (!is_empty()) {
        int cur = pop_front();
        
        if (cur == K) {
            return dist[K];
        }
        
        // 순간이동 (비용 0)
        int next = cur * 2;
        if (next < MAX && dist[next] == -1) {
            dist[next] = dist[cur];
            push_front(next);
        }
        
        // 걷기 -1 (비용 1)
        next = cur - 1;
        if (next >= 0 && dist[next] == -1) {
            dist[next] = dist[cur] + 1;
            push_back(next);
        }
        
        // 걷기 +1 (비용 1)
        next = cur + 1;
        if (next < MAX && dist[next] == -1) {
            dist[next] = dist[cur] + 1;
            push_back(next);
        }
    }
    
    return dist[K];
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    printf("%d\n", bfs(N, K));
    
    return 0;
}