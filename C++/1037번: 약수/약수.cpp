/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1037                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1037                           #+#        #+#      #+#    */
/*   Solved: 2025/11/10 12:35:14 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int min_val = 1000001;
    int max_val = 0;

    for (int i = 0; i < n; i++) {
        int divisor;
        cin >> divisor;

        min_val = min(min_val, divisor);
        max_val = max(max_val, divisor);
    }

    long long N = (long long)min_val * max_val;

    cout << N << endl;

    return 0;
}