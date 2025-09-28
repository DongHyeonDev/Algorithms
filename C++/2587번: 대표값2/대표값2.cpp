/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2587                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2587                           #+#        #+#      #+#    */
/*   Solved: 2025/09/28 19:07:51 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    std::vector<int> v(5);
    int sum = 0;

    for (int i = 0; i < 5; ++i) {
        std::cin >> v[i];
        sum += v[i];
    }
    std::sort(v.begin(), v.end());

    int avg = sum / 5;
    int med = v[2];

    std::cout << avg << '\n' << med << '\n';
    
    return 0;
}