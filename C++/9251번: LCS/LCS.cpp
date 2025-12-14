/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9251                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9251                           #+#        #+#      #+#    */
/*   Solved: 2025/12/14 18:18:37 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int len1 = str1.length();
    int len2 = str2.length();

    // dp[i][j] = str1[0..i-1]과 str2[0..j-1]의 LCS 길이
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    // DP 계산
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                // 문자가 같으면: 이전 LCS + 1
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                // 문자가 다르면: 둘 중 큰 값
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[len1][len2] << "\n";

    return 0;
}