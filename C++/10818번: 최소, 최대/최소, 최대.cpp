/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10818                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10818                          #+#        #+#      #+#    */
/*   Solved: 2025/05/03 23:20:19 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int N, min = 1000000, max = -1000000;
    std::cin >> N;
    
    for (int i = 0; i < N; ++i) {
        int num;
        std::cin >> num;
        if (num < min) min = num;
        if (num > max) max = num;
    }
    std::cout << min << " " << max << "\n";
    
    return 0;
}