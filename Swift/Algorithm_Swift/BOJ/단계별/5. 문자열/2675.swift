//
//  2675.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/26/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2675
//  알고리즘 분류: 구현, 문자열

class BOJ2675: Solvable {
    // 메모리: 79516KB, 시간: 8ms, 코드 길이: 647B
    func run() {
        // 입력 받기
        if let testCaseInput = readLine(), let testCaseCount = Int(testCaseInput) {
            var results = [String]()
            
            for _ in 0..<testCaseCount {
                if let input = readLine() {
                    let components = input.split(separator: " ")
                    if let repeatCount = Int(components[0]) {
                        let string = components[1]
                        // 반복된 문자열 생성
                        let result = string.compactMap { String(repeating: $0, count: repeatCount) }.joined()
                        results.append(result)
                    }
                }
            }
            
            // 결과 출력
            results.forEach { print($0) }
        }
    }
}
