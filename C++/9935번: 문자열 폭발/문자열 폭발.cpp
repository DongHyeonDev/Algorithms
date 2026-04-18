/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9935                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9935                           #+#        #+#      #+#    */
/*   Solved: 2026/04/18 16:17:34 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s, bomb;
    cin >> s >> bomb;
    int bLen = bomb.size();
    
    // 스택: (문자, 현재까지 매칭된 폭발 문자열 길이)
    vector<char> stk;
    vector<int> matchLen;
    stk.reserve(s.size());
    matchLen.reserve(s.size());
    
    for (char ch : s) {
        int cur = matchLen.empty() ? 0 : matchLen.back();
        
        int next;
        if (ch == bomb[cur]) {
            next = cur + 1;
        } else {
            // 폭발 문자열에 중복 문자 없으므로 KMP 불필요
            next = (ch == bomb[0]) ? 1 : 0;
        }
        
        stk.push_back(ch);
        matchLen.push_back(next);
        
        // 폭발 조건
        if (next == bLen) {
            stk.resize(stk.size() - bLen);
            matchLen.resize(matchLen.size() - bLen);
        }
    }
    
    if (stk.empty()) cout << "FRULA\n";
    else cout << string(stk.begin(), stk.end()) << "\n";
    
    return 0;
}