//
//  11021.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/14/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11021
//  알고리즘 분류: 수학, 구현, 사칙연산

class BOJ11021: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 453B
    func run() {
        // 입력 받기
        if let tInput = readLine(), let t = Int(tInput) {
            for i in 1...t {
                if let input = readLine() {
                    let numbers = input.split(separator: " ").compactMap { Int($0) }
                    if numbers.count == 2 {
                        let a = numbers[0]
                        let b = numbers[1]
                        // 출력 형식에 맞게 출력
                        print("Case #\(i): \(a + b)")
                    }
                }
            }
        }
    }
}
