//
//  27433.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/27/25.
//

//  문제 링크: https://www.acmicpc.net/problem/27433
//  알고리즘 분류: 수학, 사칙연산

class BOJ27433: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 341B
    func run() {
        // 1. 재귀 팩토리얼 함수
        func factorial(_ n: UInt64) -> UInt64 {
            return n <= 1 ? 1 : n * factorial(n - 1)
        }

        // 2. 입력 처리
        if let line = readLine(), let N = Int(line) {
            // 3. 팩토리얼 계산 (재귀 호출)
            let result = factorial(UInt64(N))
            
            // 4. 결과 출력
            print(result)
        }
    }
}
