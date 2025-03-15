/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10430                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10430                          #+#        #+#      #+#    */
/*   Solved: 2025/03/15 20:40:58 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    std::cout << (A + B) % C << std::endl;
    std::cout << ((A % C) + (B % C)) % C << std::endl;
    std::cout << (A * B) % C << std::endl;
    std::cout << ((A % C) * (B % C)) % C << std::endl;
    
    return 0;
}