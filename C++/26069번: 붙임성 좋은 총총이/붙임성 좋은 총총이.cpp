/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 26069                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/26069                          #+#        #+#      #+#    */
/*   Solved: 2025/11/12 15:55:18 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<string> dancers;

    dancers.insert("ChongChong");

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        bool a_dancing = (dancers.find(a) != dancers.end());
        bool b_dancing = (dancers.find(b) != dancers.end());

        if (a_dancing || b_dancing) {
            dancers.insert(a);
            dancers.insert(b);
        }
    }

    cout << dancers.size() << "\n";

    return 0;
}