//
//  4134.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/2/25.
//

//  문제 링크: https://www.acmicpc.net/problem/4134
//  알고리즘 분류: 수학, 브루트포스 알고리즘, 정수론, 소수 판정

class BOJ4134: Solvable {
    // 메모리: 79508KB, 시간: 56ms, 코드 길이: 697B
    func run() {
        // 소수 판별 함수
        func isPrime(_ n: Int) -> Bool {
            if n < 2 { return false }
            if n == 2 { return true }
            if n % 2 == 0 { return false }

            var i: Int = 3
            while i * i <= n {
                if n % i == 0 {
                    return false
                }
                i += 2
            }
            return true
        }

        // 테스트 케이스 수 입력
        if let t = Int(readLine() ?? "") {
            for _ in 0..<t {
                if let input = readLine(), let n = Int(input) {
                    var candidate = n
                    while true {
                        if isPrime(candidate) {
                            print(candidate)
                            break
                        }
                        candidate += 1
                    }
                }
            }
        }
    }
}
