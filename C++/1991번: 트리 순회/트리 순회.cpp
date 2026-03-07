/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1991                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1991                           #+#        #+#      #+#    */
/*   Solved: 2026/03/07 11:25:59 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
using namespace std;

char lc[26], rc[26]; // 왼쪽/오른쪽 자식
string pre, ino, post;

void traverse(char node) {
    if (node == '.') return;
    int idx = node - 'A';
    pre  += node;              // 전위: 루트 먼저
    traverse(lc[idx]);
    ino  += node;              // 중위: 왼쪽 후
    traverse(rc[idx]);
    post += node;              // 후위: 오른쪽 후
}

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        char node, l, r;
        cin >> node >> l >> r;
        lc[node - 'A'] = l;
        rc[node - 'A'] = r;
    }
    
    traverse('A');
    
    cout << pre  << "\n"
         << ino  << "\n"
         << post << "\n";
    
    return 0;
}