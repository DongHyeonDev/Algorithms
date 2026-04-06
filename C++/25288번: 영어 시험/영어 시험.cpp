/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25288                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25288                          #+#        #+#      #+#    */
/*   Solved: 2026/04/06 13:26:18 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    string s; cin >> s;
    sort(s.begin(), s.end());  // 알파벳 정렬
    
    // 정렬된 알파벳을 N번 반복
    for (int i = 0; i < N; i++) cout << s;
    cout << "\n";
    return 0;
}