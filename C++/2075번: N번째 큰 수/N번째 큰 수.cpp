/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2075                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2075                           #+#        #+#      #+#    */
/*   Solved: 2026/01/13 14:37:52 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    priority_queue<int, vector<int>, greater<int>> min_heap;
    
    for (int i = 0; i < N; i++) {
        vector<int> row(N);
        for (int j = 0; j < N; j++) {
            cin >> row[j];
        }
        
        // 행을 내림차순 정렬
        sort(row.begin(), row.end(), greater<int>());
        
        for (int j = 0; j < N; j++) {
            if (min_heap.size() < N) {
                min_heap.push(row[j]);
            } else if (row[j] > min_heap.top()) {
                min_heap.pop();
                min_heap.push(row[j]);
            } else {
                // 이후 값들은 더 작으므로 중단
                break;
            }
        }
    }
    
    cout << min_heap.top() << "\n";
    
    return 0;
}