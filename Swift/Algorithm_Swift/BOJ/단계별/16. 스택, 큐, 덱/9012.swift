//
//  9012.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/9/25.
//

//  문제 링크: https://www.acmicpc.net/problem/9012
//  알고리즘 분류: 자료 구조, 문자열, 스택

class BOJ9012: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 805B
    func run() {
        // 테스트 케이스 개수 입력
        if let tInput = readLine(), let t = Int(tInput) {
            for _ in 0..<t {
                if let ps = readLine() {
                    var stack: [Character] = []
                    var isValid = true

                    for char in ps {
                        if char == "(" {
                            stack.append(char)
                        } else if char == ")" {
                            if stack.isEmpty {
                                isValid = false
                                break
                            } else {
                                stack.removeLast()
                            }
                        }
                    }

                    // 스택이 비어있어야 VPS
                    if isValid && stack.isEmpty {
                        print("YES")
                    } else {
                        print("NO")
                    }
                }
            }
        }
    }
}
