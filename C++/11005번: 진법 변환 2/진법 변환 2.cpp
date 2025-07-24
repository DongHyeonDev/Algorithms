/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11005                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11005                          #+#        #+#      #+#    */
/*   Solved: 2025/07/24 18:35:42 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

int main() {
    long long N;
    int B;
    std::cin >> N >> B;

    if (N == 0) {
        std::cout << '0' << "\n";
        return 0;
    }

    std::string result;
    while (N > 0) {
        int digit = N % B;
        if (digit < 10) {
            result.push_back('0' + digit);
        } else {
            result.push_back('A' + (digit - 10));
        }
        N /= B;
    }

    for (int i = result.length() - 1; i >= 0; --i) {
        std::cout << result[i];
    }
    std::cout << "\n";

    return 0;
}