/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4134                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4134                           #+#        #+#      #+#    */
/*   Solved: 2025/10/20 11:24:48 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

long long nextPrime(long long n) {
    if (n <= 2) return 2;
    long long prime = n;

    for (long long i = 2; i <= (long long)std::sqrt((long double)prime); ++i) {
        if (prime % i == 0) {
            ++prime;
            i = 1;
        }
    }
    
    return prime;
}

int main() {
    long long T, n;
    if (!(std::cin >> T)) return 0;
    
    while (T--) {
        std::cin >> n;
        std::cout << nextPrime(n) << '\n';
    }
    
    return 0;
}