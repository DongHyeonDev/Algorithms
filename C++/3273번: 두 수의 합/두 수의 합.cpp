/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 3273                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/3273                           #+#        #+#      #+#    */
/*   Solved: 2026/02/11 13:37:41 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    int arr[100000];
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    
    // 정렬
    sort(arr, arr + n);
    
    // 투 포인터
    int left = 0;
    int right = n - 1;
    int count = 0;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (sum == x) {
            count++;
            left++;
            right--;
        } else if (sum < x) {
            left++;
        } else {
            right--;
        }
    }
    
    cout << count << "\n";
    
    return 0;
}