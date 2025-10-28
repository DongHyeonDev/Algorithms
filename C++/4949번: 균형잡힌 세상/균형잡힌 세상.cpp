/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4949                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4949                           #+#        #+#      #+#    */
/*   Solved: 2025/10/28 14:48:41 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line == ".") break;

        std::stack<char> stk;
        bool isBalanced = true;

        for (char ch : line) {
            if (ch == '(' || ch == '[') {
                stk.push(ch);
            } else if (ch == ')') {
                if (stk.empty() || stk.top() != '(') {
                    isBalanced = false;
                    break;
                }
                stk.pop();
            } else if (ch == ']') {
                if (stk.empty() || stk.top() != '[') {
                    isBalanced = false;
                    break;
                }
                stk.pop();
            }
        }

        if (isBalanced && stk.empty()) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }
    return 0;
}