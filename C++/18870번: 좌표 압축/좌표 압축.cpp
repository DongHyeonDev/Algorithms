/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 18870                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/18870                          #+#        #+#      #+#    */
/*   Solved: 2025/10/07 12:34:01 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N; 
    if (!(std::cin >> N)) return 0;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) std::cin >> a[i];

    std::vector<int> u = a;
    std::sort(u.begin(), u.end());
    u.erase(std::unique(u.begin(), u.end()), u.end());

    for (int i = 0; i < N; ++i) {
        int rank = int(std::lower_bound(u.begin(), u.end(), a[i]) - u.begin());
        std::cout << rank << (i+1==N?'\n':' ');
    }
    return 0;
}