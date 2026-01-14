/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2696                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2696                           #+#        #+#      #+#    */
/*   Solved: 2026/01/14 15:32:58 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int M;
        cin >> M;
        
        // 최대 힙 (왼쪽 절반, 작은 값들)
        priority_queue<int> max_heap;
        
        // 최소 힙 (오른쪽 절반, 큰 값들)
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        vector<int> medians;
        
        for (int i = 1; i <= M; i++) {
            int num;
            cin >> num;
            
            // 1. 최대 힙에 추가 (또는 최소 힙)
            if (max_heap.empty() || num <= max_heap.top()) {
                max_heap.push(num);
            } else {
                min_heap.push(num);
            }
            
            // 2. 힙 크기 균형 맞추기
            if (max_heap.size() > min_heap.size() + 1) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            } else if (min_heap.size() > max_heap.size()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            
            // 3. 홀수번째면 중앙값 저장
            if (i % 2 == 1) {
                medians.push_back(max_heap.top());
            }
        }
        
        // 출력
        cout << medians.size() << "\n";
        for (int i = 0; i < medians.size(); i++) {
            cout << medians[i];
            if ((i + 1) % 10 == 0 || i == medians.size() - 1) {
                cout << "\n";
            } else {
                cout << " ";
            }
        }
    }
    
    return 0;
}