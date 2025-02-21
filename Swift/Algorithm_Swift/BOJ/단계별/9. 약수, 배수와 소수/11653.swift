//
//  11653.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/21/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11653
//  알고리즘 분류: 수학, 정수론, 소수 판정

class BOJ11653: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 601B
    func run() {
        /// 정수를 소인수분해하는 함수
        /// - Parameter n: 소인수분해할 정수
        func primeFactorization(_ n: Int) {
            var number = n
            var factor = 2 // 가장 작은 소수부터 시작

            while factor * factor <= number {
                while number % factor == 0 {
                    print(factor) // 소인수 출력
                    number /= factor
                }
                factor += 1
            }

            // 마지막으로 남은 소수가 있으면 출력
            if number > 1 {
                print(number)
            }
        }

        // 입력 처리
        if let N = Int(readLine() ?? "0"), N > 1 {
            primeFactorization(N)
        }
    }
}
