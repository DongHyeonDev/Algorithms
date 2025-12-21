/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25682                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25682                          #+#        #+#      #+#    */
/*   Solved: 2025/12/21 16:35:45 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<string> board(N + 1);
    vector<vector<int>> prefix1(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> prefix2(N + 1, vector<int>(M + 1, 0));

    // 보드 입력
    board[0] = string(M + 1, ' ');
    for (int i = 1; i <= N; i++) {
        string row;
        cin >> row;
        board[i] = " " + row;
    }

    // 누적 합 계산
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            // 패턴1: (i+j)가 짝수면 W, 홀수면 B
            char expected1 = ((i + j) % 2 == 0) ? 'W' : 'B';
            int diff1 = (board[i][j] != expected1) ? 1 : 0;

            // 패턴2: (i+j)가 짝수면 B, 홀수면 W
            char expected2 = ((i + j) % 2 == 0) ? 'B' : 'W';
            int diff2 = (board[i][j] != expected2) ? 1 : 0;

            prefix1[i][j] = diff1 + prefix1[i-1][j] + prefix1[i][j-1] - prefix1[i-1][j-1];
            prefix2[i][j] = diff2 + prefix2[i-1][j] + prefix2[i][j-1] - prefix2[i-1][j-1];
        }
    }

    // 모든 K×K 영역 확인
    int min_cost = K * K;
    for (int i = K; i <= N; i++) {
        for (int j = K; j <= M; j++) {
            // (i-K+1, j-K+1)부터 (i, j)까지의 K×K 영역
            int cost1 = prefix1[i][j] - prefix1[i-K][j] - prefix1[i][j-K] + prefix1[i-K][j-K];
            int cost2 = prefix2[i][j] - prefix2[i-K][j] - prefix2[i][j-K] + prefix2[i-K][j-K];

            int cost = min(cost1, cost2);
            min_cost = min(min_cost, cost);
        }
    }

    cout << min_cost << "\n";

    return 0;
}