//
//  2581.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/20/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2581
//  알고리즘 분류: 수학, 정수론, 소수 판정

class BOJ2581: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 1168B
    func run() {
        /// 주어진 숫자가 소수인지 판별하는 함수
        /// - Parameter number: 검사할 정수
        /// - Returns: 소수이면 `true`, 아니면 `false`
        func isPrime(_ number: Int) -> Bool {
            if number < 2 { return false } // 1 이하의 숫자는 소수가 아님
            if number == 2 { return true } // 2는 소수
            if number % 2 == 0 { return false } // 짝수는 소수가 아님 (2 제외)

            let sqrtNum = Int(Double(number).squareRoot()) // √N까지만 검사
            for i in stride(from: 3, through: sqrtNum, by: 2) { // 홀수만 체크
                if number % i == 0 {
                    return false
                }
            }
            return true
        }

        // M과 N 입력 받기
        if let M = Int(readLine() ?? "0"), let N = Int(readLine() ?? "0") {
            var primes = [Int]() // 소수를 저장할 배열

            // M부터 N까지 순회하며 소수 찾기
            for num in M...N {
                if isPrime(num) {
                    primes.append(num)
                }
            }

            // 결과 출력
            if primes.isEmpty {
                print(-1) // 소수가 없을 경우
            } else {
                print(primes.reduce(0, +)) // 소수의 합
                print(primes.first!) // 소수 중 최솟값
            }
        }
    }
}
