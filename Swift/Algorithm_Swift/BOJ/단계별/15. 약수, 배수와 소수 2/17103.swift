//
//  17103.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/5/25.
//

//  문제 링크: https://www.acmicpc.net/problem/17103
//  알고리즘 분류: 수학, 정수론, 소수 판정, 에라토스테네스의 체

import Foundation

class BOJ17103: Solvable {
    // 메모리: 80488KB, 시간: 80ms, 코드 길이: 850B
    func run() {
        // 최대 범위 설정
        let maxN = 1_000_000

        // 에라토스테네스의 체로 소수 판별 배열 생성
        var isPrime = [Bool](repeating: true, count: maxN + 1)
        isPrime[0] = false
        isPrime[1] = false

        for i in 2...Int(sqrt(Double(maxN))) {
            if isPrime[i] {
                var j = i * i
                while j <= maxN {
                    isPrime[j] = false
                    j += i
                }
            }
        }

        // 테스트 케이스 수 입력
        if let t = Int(readLine() ?? "") {
            for _ in 0..<t {
                if let line = readLine(), let n = Int(line) {
                    var count = 0
                    // 두 소수의 합으로 표현되도록 작은 쪽만 탐색 (중복 제거)
                    for i in 2...(n / 2) {
                        if isPrime[i] && isPrime[n - i] {
                            count += 1
                        }
                    }
                    print(count)
                }
            }
        }
    }
}
