/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1010                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1010                           #+#        #+#      #+#    */
/*   Solved: 2025/11/09 14:29:24 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    long long dp[30][30] = {0};

    for (int i = 0; i < 30; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for (int i = 2; i < 30; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    while (T--) {
        int N, M;
        cin >> N >> M;

        cout << dp[M][N] << endl;
    }

    return 0;
}