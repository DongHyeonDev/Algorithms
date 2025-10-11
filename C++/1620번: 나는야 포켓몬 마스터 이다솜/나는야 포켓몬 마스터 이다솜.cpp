/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1620                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1620                           #+#        #+#      #+#    */
/*   Solved: 2025/10/11 12:38:56 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    int n, m;
    if (!(std::cin >> n >> m)) return 0;

    std::unordered_map<std::string, int> pokemon_to_number;
    std::unordered_map<int, std::string> number_to_pokemon;
    pokemon_to_number.reserve(n);
    number_to_pokemon.reserve(n);

    for (int i = 1; i <= n; ++i) {
        std::string pokemon;
        std::cin >> pokemon;
        pokemon_to_number[pokemon] = i;
        number_to_pokemon[i] = pokemon;
    }

    for (int i = 0; i < m; ++i) {
        std::string query;
        std::cin >> query;
        if (isdigit(query[0])) {
            int number = std::stoi(query);
            std::cout << number_to_pokemon[number] << '\n';
        } else {
            std::cout << pokemon_to_number[query] << '\n';
        }
    }
    return 0;
}