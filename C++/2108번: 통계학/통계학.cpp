/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2108                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2108                           #+#        #+#      #+#    */
/*   Solved: 2025/11/13 13:43:56 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_VAL = 4000;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    long long sum = 0;

    vector<int> freq(MAX_VAL * 2 + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        freq[arr[i] + MAX_VAL]++;
    }

    double avg = (double)sum / n;
    int mean = (int)round(avg);
    cout << mean << "\n";

    sort(arr.begin(), arr.end());
    cout << arr[n / 2] << "\n";

    int max_freq = 0;

    for (int i = 0; i <= MAX_VAL * 2; i++) {
        max_freq = max(max_freq, freq[i]);
    }

    vector<int> modes;
    for (int i = 0; i <= MAX_VAL * 2; i++) {
        if (freq[i] == max_freq) {
            modes.push_back(i - MAX_VAL);
            if (modes.size() == 2) break;
        }
    }

    if (modes.size() > 1) {
        cout << modes[1] << "\n";
    } else {
        cout << modes[0] << "\n";
    }

    cout << arr[n - 1] - arr[0] << "\n";

    return 0;
}