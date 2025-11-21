/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11729                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11729                          #+#        #+#      #+#    */
/*   Solved: 2025/11/21 14:19:20 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        cout << from << " " << to << "\n";
        return;
    }

    hanoi(n - 1, from, aux, to);

    cout << from << " " << to << "\n";

    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    cin >> n;

    long long total_moves = (1LL << n) - 1;
    cout << total_moves << "\n";

    hanoi(n, 1, 3, 2);

    return 0;
}