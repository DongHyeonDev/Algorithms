/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2750                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2750                           #+#        #+#      #+#    */
/*   Solved: 2025/09/27 16:03:23 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int N;
    if (!(std::cin >> N)) return 0;

    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) std::cin >> a[i];

    std::sort(a.begin(), a.end()); // 오름차순 기본 정렬

    for (int x : a) std::cout << x << '\n';
    return 0;
}