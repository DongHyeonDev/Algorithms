/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4779                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4779                           #+#        #+#      #+#    */
/*   Solved: 2025/11/19 14:46:33 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void cantor(string& line, int start, int length) {
    if (length == 1) {
        return;
    }

    int third = length / 3;

    for (int i = start + third; i < start + 2 * third; i++) {
        line[i] = ' ';
    }

    cantor(line, start, third);
    cantor(line, start + 2 * third, third);
}

int main() {
    int n;

    while (cin >> n) {
        int length = (int)pow(3, n);

        string line(length, '-');

        cantor(line, 0, length);

        cout << line << "\n";
    }

    return 0;
}