/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10815                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10815                          #+#        #+#      #+#    */
/*   Solved: 2025/10/08 20:11:34 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N; 
    if (!(std::cin >> N)) return 0;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    } 

    std::sort(a.begin(), a.end());

    int M; 
    std::cin >> M;
    for (int i = 0; i < M; ++i) {
        int x;
        std::cin >> x;
        bool ok = std::binary_search(a.begin(), a.end(), x);
        std::cout << (ok ? 1 : 0) << (i+1==M?'\n':' ');
    }
    return 0;
}