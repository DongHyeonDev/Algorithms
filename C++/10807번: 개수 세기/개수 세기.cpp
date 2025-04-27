/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10807                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10807                          #+#        #+#      #+#    */
/*   Solved: 2025/04/27 14:25:57 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int N, v, count = 0;
    std::cin >> N;

    int arr[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }
    std::cin >> v;

    for (int i = 0; i < N; ++i) {
        if (arr[i] == v) {
            ++count;
        }
    }

    std::cout << count << "\n";
    return 0;
}