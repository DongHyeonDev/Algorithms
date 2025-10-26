/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10773                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10773                          #+#        #+#      #+#    */
/*   Solved: 2025/10/26 14:54:19 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int K, x;
    static int stk[100000];
    int top = 0;
    long long sum = 0;

    if (!(std::cin >> K)) return 0;
    for (int i = 0; i < K; ++i) {
        std::cin >> x;
        if (x == 0) {
            sum -= stk[--top];
        } else {
            stk[top++] = x;
            sum += x;
        }
    }
    std::cout << sum << '\n';
    return 0;
}