/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25192                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25192                          #+#        #+#      #+#    */
/*   Solved: 2025/11/11 12:03:29 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<string> users;
    int gomgom_count = 0;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        if (input == "ENTER") {
            users.clear();
        } else {
            if (users.find(input) == users.end()) {
                gomgom_count++;
                users.insert(input);
            }
        }
    }

    cout << gomgom_count << "\n";

    return 0;
}