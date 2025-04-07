//
//  28278.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/7/25.
//

//  문제 링크: https://www.acmicpc.net/problem/28278
//  알고리즘 분류: 자료 구조, 스택

class BOJ28278: Solvable {
    // 메모리: 92644KB, 시간: 920ms, 코드 길이: 906B
    func run() {
        // 빠른 입출력을 위한 최적화
        var output = ""
        var stack: [Int] = []

        let n = Int(readLine()!)!

        for _ in 0..<n {
            let command = readLine()!.split(separator: " ")
            
            switch command[0] {
            case "1":
                // 1 X: 정수 X를 스택에 넣는다
                if let x = Int(command[1]) {
                    stack.append(x)
                }
            case "2":
                // 2: 맨 위의 정수를 빼고 출력
                output += (stack.popLast().map { "\($0)" } ?? "-1") + "\n"
            case "3":
                // 3: 스택에 들어있는 정수 개수 출력
                output += "\(stack.count)\n"
            case "4":
                // 4: 스택이 비어있으면 1, 아니면 0 출력
                output += (stack.isEmpty ? "1" : "0") + "\n"
            case "5":
                // 5: 맨 위의 정수 출력 (제거는 X)
                output += (stack.last.map { "\($0)" } ?? "-1") + "\n"
            default:
                break
            }
        }

        print(output)
    }
}
