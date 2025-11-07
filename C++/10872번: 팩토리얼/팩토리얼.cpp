/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10872                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10872                          #+#        #+#      #+#    */
/*   Solved: 2025/11/07 12:27:28 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long result = 1;

    for (int i = 2; i <= N; i++) {
        result *= i;
    }

    cout << result << endl;

    return 0;
}