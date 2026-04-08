/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 31836                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/31836                          #+#        #+#      #+#    */
/*   Solved: 2026/04/08 14:27:19 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A, B;

    if (N % 3 == 0) {
        for (int i = 1; i <= N; i++) {
            if (i % 3 == 0) B.push_back(i);
            else A.push_back(i);
        }
    } else if (N % 3 == 2) {
        for (int i = 1; i <= N; i++) {
            if (i % 3 == 2) B.push_back(i);
            else A.push_back(i);
        }
    } else { // N % 3 == 1
        for (int i = 1; i < N; i++) {
            if (i % 3 == 0) B.push_back(i);
            else A.push_back(i);
        }
    }

    cout << A.size() << '\n';
    for (int i = 0; i < (int)A.size(); i++) {
        if (i) cout << ' ';
        cout << A[i];
    }
    cout << '\n';

    cout << B.size() << '\n';
    for (int i = 0; i < (int)B.size(); i++) {
        if (i) cout << ' ';
        cout << B[i];
    }
    cout << '\n';

    return 0;
}