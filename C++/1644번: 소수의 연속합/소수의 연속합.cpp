/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1644                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1644                           #+#        #+#      #+#    */
/*   Solved: 2026/02/14 13:17:37 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primes;

void sieve(int N) {
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    int limit = (int)sqrt(N);
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    // 소수 목록 생성
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    // 에라토스테네스의 체
    sieve(N);
    
    // 투 포인터
    int left = 0;
    int right = 0;
    int sum = 0;
    int count = 0;
    
    while (true) {
        if (sum >= N) {
            if (sum == N) {
                count++;
            }
            sum -= primes[left];
            left++;
        } else if (right == primes.size()) {
            break;
        } else {
            sum += primes[right];
            right++;
        }
    }
    
    cout << count << "\n";
    
    return 0;
}