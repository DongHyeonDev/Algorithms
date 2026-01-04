/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1920                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1920                           #+#        #+#      #+#    */
/*   Solved: 2026/01/04 06:18:28 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 정렬
    sort(A.begin(), A.end());

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;

        // binary_search: 존재하면 true, 없으면 false
        if (binary_search(A.begin(), A.end(), x)) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}