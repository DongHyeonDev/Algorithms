/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 28065                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/28065                          #+#        #+#      #+#    */
/*   Solved: 2026/04/02 13:20:31 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int lo = 1, hi = N;
    bool first = true;
    while (lo <= hi) {
        if (!first) cout << " ";
        cout << hi--; first = false;
        if (lo <= hi) cout << " " << lo++;
    }
    cout << "\n";
    return 0;
}