/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 16139                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/16139                          #+#        #+#      #+#    */
/*   Solved: 2025/12/18 13:17:07 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string S;
    cin >> S;

    int len = S.length();

    // 누적 합 배열: prefix[i][j] = 0번째부터 j번째까지 알파벳 i의 개수
    vector<vector<int>> prefix(26, vector<int>(len + 1, 0));

    // 누적 합 계산
    for (int j = 0; j < len; j++) {
        int ch = S[j] - 'a';
        for (int i = 0; i < 26; i++) {
            if (i == ch) {
                prefix[i][j + 1] = prefix[i][j] + 1;
            } else {
                prefix[i][j + 1] = prefix[i][j];
            }
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        char alpha;
        int l, r;
        cin >> alpha >> l >> r;

        int idx = alpha - 'a';
        int count = prefix[idx][r + 1] - prefix[idx][l];

        cout << count << "\n";
    }

    return 0;
}