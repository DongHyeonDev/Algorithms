/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 13018                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/13018                          #+#        #+#      #+#    */
/*   Solved: 2026/04/10 12:24:37 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    
    if (k > n-1) { cout << "Impossible\n"; return 0; }
    
    vector<int> A(n+1);
    for (int i = 1; i <= n; i++) A[i] = i;
    
    int need = (n-1) - k;
    int startPair = 2;
    
    // 홀수 감소: (1,2) 교환으로 -1
    if (need % 2 == 1) {
        swap(A[1], A[2]);
        need--;
        startPair = 3;  // (1,2,3)이 얽혔으므로 4부터
    }
    
    // 짝수 감소: (pos, pos+1) 교환으로 -2씩
    for (int pos = startPair; need > 0; pos += 2, need -= 2)
        swap(A[pos], A[pos+1]);
    
    for (int i = 1; i <= n; i++) {
        cout << A[i];
        if (i < n) cout << " ";
    }
    cout << "\n";
    return 0;
}