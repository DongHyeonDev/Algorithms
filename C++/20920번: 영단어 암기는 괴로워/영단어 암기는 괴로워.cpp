/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 20920                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/20920                          #+#        #+#      #+#    */
/*   Solved: 2025/11/14 01:36:44 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Word {
    string word;
    int freq;
    int len;
};

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<string, int> freq_map;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        if (word.length() < m) continue;

        freq_map[word]++;
    }

    vector<Word> words;
    for (auto& p : freq_map) {
        words.push_back({p.first, p.second, (int)p.first.length()});
    }

    sort(words.begin(), words.end(), [](const Word& a, const Word& b) {
        if (a.freq != b.freq) {
            return a.freq > b.freq;
        }

        if (a.len != b.len) {
            return a.len > b.len;
        }

        return a.word < b.word;
    });

    for (const auto& w : words) {
        cout << w.word << "\n";
    }

    return 0;
}