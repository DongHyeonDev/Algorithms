/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 27433                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/27433                          #+#        #+#      #+#    */
/*   Solved: 2025/11/15 23:44:02 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

using namespace std;

long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    
    return n * factorial(n - 1);
}

int main() {
    int n;
    cin >> n;
    
    cout << factorial(n) << "\n";
    
    return 0;
}