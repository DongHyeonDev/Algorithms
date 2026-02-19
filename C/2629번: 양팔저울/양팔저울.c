/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2629                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2629                           #+#        #+#      #+#    */
/*   Solved: 2026/02/19 13:07:45 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int N, Q;
int weights[30];
// visited[i][diff] : i번째 추까지 사용했을 때 차이가 diff인 경우 가능한지
// diff = 구슬쪽 합 - 추쪽 합, 범위: -15000 ~ 15000, offset 15000
#define OFFSET 15000
#define SIZE 30001
int visited[31][SIZE];

void dfs(int idx, int diff) {
    if (visited[idx][diff + OFFSET]) return;
    visited[idx][diff + OFFSET] = 1;
    
    if (idx == N) return;
    
    // 추를 사용 안함
    dfs(idx + 1, diff);
    // 추를 구슬 반대쪽에 올림 (추쪽에 추가)
    dfs(idx + 1, diff - weights[idx]);
    // 추를 구슬 같은쪽에 올림 (구슬쪽에 추가, diff 증가)
    dfs(idx + 1, diff + weights[idx]);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &weights[i]);
    
    memset(visited, 0, sizeof(visited));
    dfs(0, 0);
    
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int marble;
        scanf("%d", &marble);
        // 구슬 무게 = marble, 저울이 수평 -> diff = marble (구슬쪽이 marble만큼 더 무거운 상태에서 균형)
        // 실제로 구슬을 왼쪽, 추들을 양쪽에 놓는다
        // diff = 구슬쪽 추 합 - 반대쪽 추 합 = -marble 이어야 균형
        if (marble <= OFFSET && visited[N][-marble + OFFSET])
            printf("Y");
        else
            printf("N");
        if (i < Q - 1) printf(" ");
    }
    printf("\n");
    return 0;
}