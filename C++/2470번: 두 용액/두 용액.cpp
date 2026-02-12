/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2470                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2470                           #+#        #+#      #+#    */
/*   Solved: 2026/02/12 12:10:33 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    int arr[100000];
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // 정렬
    sort(arr, arr + n);
    
    // 투 포인터
    int left = 0;
    int right = n - 1;
    long long min_diff = 2000000001LL;
    int result_left = 0;
    int result_right = 0;
    
    while (left < right) {
        long long sum = (long long)arr[left] + arr[right];
        long long diff = abs(sum);
        
        if (diff < min_diff) {
            min_diff = diff;
            result_left = arr[left];
            result_right = arr[right];
        }
        
        if (sum == 0) {
            break;
        } else if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }
    
    cout << result_left << " " << result_right << "\n";
    
    return 0;
}