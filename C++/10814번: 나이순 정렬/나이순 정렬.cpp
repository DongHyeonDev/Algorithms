/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10814                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10814                          #+#        #+#      #+#    */
/*   Solved: 2025/10/06 11:37:35 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

struct Member {
    int age;
    int idx;
    std::string name;
};

int main() {
    int N; 
    if (!(std::cin >> N)) return 0;

    std::vector<Member> v(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> v[i].age >> v[i].name;
        v[i].idx = i;
    }

    std::stable_sort(v.begin(), v.end(), [](const Member& a, const Member& b){ return a.age < b.age; });

    for (const auto& m : v) {
        std::cout << m.age << ' ' << m.name << '\n';
    }
    return 0;
}