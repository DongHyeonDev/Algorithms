/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25501                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25501                          #+#        #+#      #+#    */
/*   Solved: 2025/11/17 10:25:14 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

using namespace std;

int call_count;

int recursion(const string& s, int l, int r) {
    call_count++;

    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const string& s) {
    return recursion(s, 0, s.length() - 1);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        call_count = 0;
        int result = isPalindrome(s);

        cout << result << " " << call_count << "\n";
    }

    return 0;
}