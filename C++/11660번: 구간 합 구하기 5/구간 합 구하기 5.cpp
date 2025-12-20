/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11660                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11660                          #+#        #+#      #+#    */
/*   Solved: 2025/12/20 20:35:11 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // 배열과 누적 합 배열 (1-indexed)
    vector<vector<int>> arr(N + 1, vector<int>(N + 1));
    vector<vector<long long>> prefix(N + 1, vector<long long>(N + 1, 0));

    // 배열 입력 및 누적 합 계산
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            prefix[i][j] = arr[i][j] 
                         + prefix[i-1][j] 
                         + prefix[i][j-1] 
                         - prefix[i-1][j-1];
        }
    }

    // 쿼리 처리
    for (int q = 0; q < M; q++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long result = prefix[x2][y2] 
                         - prefix[x1-1][y2] 
                         - prefix[x2][y1-1] 
                         + prefix[x1-1][y1-1];

        cout << result << "\n";
    }

    return 0;
}