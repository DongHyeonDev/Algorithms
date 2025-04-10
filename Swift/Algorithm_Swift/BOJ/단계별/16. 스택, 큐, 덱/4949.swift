//
//  4949.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/10/25.
//

//  문제 링크: https://www.acmicpc.net/problem/4949
//  알고리즘 분류: 자료 구조, 문자열, 스택

class BOJ4949: Solvable {
    // 메모리: 79504KB, 시간: 24ms, 코드 길이: 1038B
    func run() {
        while let line = readLine(), line != "." {
            var stack: [Character] = []     // 괄호를 저장할 스택
            var isBalanced = true           // 균형 여부를 저장하는 변수

            for char in line {
                if char == "(" || char == "[" {
                    stack.append(char)      // 여는 괄호는 스택에 push
                } else if char == ")" {
                    if stack.last == "(" {
                        stack.removeLast()  // 짝이 맞는 괄호 pop
                    } else {
                        isBalanced = false  // 짝이 안 맞으면 실패 처리
                        break
                    }
                } else if char == "]" {
                    if stack.last == "[" {
                        stack.removeLast()  // 짝이 맞는 대괄호 pop
                    } else {
                        isBalanced = false  // 짝이 안 맞으면 실패 처리
                        break
                    }
                }
            }

            // 모든 괄호가 잘 짝지어졌고 스택이 비어있으면 yes
            if isBalanced && stack.isEmpty {
                print("yes")
            } else {
                print("no")
            }
        }
    }
}
