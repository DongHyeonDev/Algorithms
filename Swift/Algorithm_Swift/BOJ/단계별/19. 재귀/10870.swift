//
//  10870.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/28/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10870
//  알고리즘 분류: 수학, 구현

class BOJ10870: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 296B
    func run() {
        // 입력 받기
        let n = Int(readLine() ?? "") ?? 0

        // 피보나치 계산 (0 ≤ n ≤ 20)
        var a = 0
        var b = 1

        if n == 0 {
            print(a)
        } else if n == 1 {
            print(b)
        } else {
            for _ in 2...n {
                let next = a + b
                a = b
                b = next
            }
            print(b)
        }
    }
}
