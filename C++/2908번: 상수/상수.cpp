/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2908                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2908                           #+#        #+#      #+#    */
/*   Solved: 2025/06/05 21:31:52 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string A, B;
    std::cin >> A >> B;

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    int a = stoi(A);
    int b = stoi(B);

    std::cout << (a > b ? a : b) << "\n";
    return 0;
}