/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1436                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1436                           #+#        #+#      #+#    */
/*   Solved: 2025/09/25 16:58:31 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

static bool has666(int x) {
    int run = 0;
    while (x > 0) {
        if (x % 10 == 6) {
            if (++run >= 3) return true;
        } else {
            run = 0;
        }
        x /= 10;
    }
    return false;
}

int main() {
    int N; 
    if (!(std::cin >> N)) return 0;

    int count = 0;
    int num = 666;
    while (true) {
        if (has666(num)) {
            if (++count == N) {
                std::cout << num << '\n';
                break;
            }
        }
        ++num;
    }
    return 0;
}