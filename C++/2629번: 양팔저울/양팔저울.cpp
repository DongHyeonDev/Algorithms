/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2629                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2629                           #+#        #+#      #+#    */
/*   Solved: 2026/02/19 13:07:50 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <cstring>
using namespace std;

#define OFFSET 15000
#define SIZE 30001

int N, Q;
int weights[30];
bool visited[31][SIZE];

void dfs(int idx, int diff) {
    if (visited[idx][diff + OFFSET]) return;
    visited[idx][diff + OFFSET] = true;
    
    if (idx == N) return;
    
    dfs(idx + 1, diff);                    // 추 안 씀
    dfs(idx + 1, diff - weights[idx]);     // 추를 반대쪽에
    dfs(idx + 1, diff + weights[idx]);     // 추를 구슬쪽에
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> weights[i];
    
    memset(visited, false, sizeof(visited));
    dfs(0, 0);
    
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int marble;
        cin >> marble;
        if (marble <= OFFSET && visited[N][-marble + OFFSET])
            cout << "Y";
        else
            cout << "N";
        if (i < Q - 1) cout << " ";
    }
    cout << "\n";
    return 0;
}