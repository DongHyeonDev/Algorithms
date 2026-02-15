/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1450                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1450                           #+#        #+#      #+#    */
/*   Solved: 2026/02/15 19:43:52 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int weights[30];
int N, C;

void make_sums(int start, int end, vector<long long>& sums) {
    int size = end - start;
    
    for (int mask = 0; mask < (1 << size); mask++) {
        long long sum = 0;
        for (int i = 0; i < size; i++) {
            if (mask & (1 << i)) {
                sum += weights[start + i];
            }
        }
        sums.push_back(sum);
    }
}

int main() {
    cin >> N >> C;
    
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }
    
    int mid = N / 2;
    
    vector<long long> left_sums, right_sums;
    
    // 왼쪽 절반의 모든 부분집합 합
    make_sums(0, mid, left_sums);
    
    // 오른쪽 절반의 모든 부분집합 합
    make_sums(mid, N, right_sums);
    
    // 오른쪽 정렬
    sort(right_sums.begin(), right_sums.end());
    
    long long count = 0;
    
    // 왼쪽 각 합에 대해 오른쪽에서 가능한 개수 찾기
    for (long long left_sum : left_sums) {
        long long remain = C - left_sum;
        if (remain >= 0) {
            // remain 이하인 개수
            count += upper_bound(right_sums.begin(), right_sums.end(), remain) 
                     - right_sums.begin();
        }
    }
    
    cout << count << "\n";
    
    return 0;
}