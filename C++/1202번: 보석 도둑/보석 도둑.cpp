/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1202                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1202                           #+#        #+#      #+#    */
/*   Solved: 2026/01/15 11:39:46 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    // 보석: {무게, 가격}
    vector<pair<int, int>> jewels(N);
    for (int i = 0; i < N; i++) {
        cin >> jewels[i].first >> jewels[i].second;
    }
    
    // 가방 용량
    vector<int> bags(K);
    for (int i = 0; i < K; i++) {
        cin >> bags[i];
    }
    
    // 보석을 무게 오름차순 정렬
    sort(jewels.begin(), jewels.end());
    
    // 가방을 용량 오름차순 정렬
    sort(bags.begin(), bags.end());
    
    // 최대 힙 (가격 기준)
    priority_queue<int> max_heap;
    
    long long total = 0;
    int jewel_idx = 0;
    
    // 각 가방에 대해 처리
    for (int i = 0; i < K; i++) {
        // 현재 가방에 담을 수 있는 모든 보석을 힙에 추가
        while (jewel_idx < N && jewels[jewel_idx].first <= bags[i]) {
            max_heap.push(jewels[jewel_idx].second);
            jewel_idx++;
        }
        
        // 힙에서 가장 비싼 보석 선택
        if (!max_heap.empty()) {
            total += max_heap.top();
            max_heap.pop();
        }
    }
    
    cout << total << "\n";
    
    return 0;
}