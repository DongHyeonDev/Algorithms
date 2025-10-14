/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1269                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1269                           #+#        #+#      #+#    */
/*   Solved: 2025/10/14 17:26:29 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    if (!(std::cin >> n >> m)) return 0;

    std::vector<int> A(n), B(m);
    for (int i = 0; i < n; ++i) std::cin >> A[i];
    for (int j = 0; j < m; ++j) std::cin >> B[j];

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    int i = 0, j = 0, common = 0;
    while (i < n && j < m) {
        if (A[i] == B[j]) { ++common; ++i; ++j; }
        else if (A[i] < B[j]) { ++i; }
        else { ++j; }
    }

    long long ans = 1LL * n + m - 2LL * common;
    std::cout << ans << '\n';
    return 0;
}