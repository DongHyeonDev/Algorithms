//
//  1978.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/19/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1978
//  알고리즘 분류: 수학, 정수론, 소수 판정

class BOJ1978: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 1149B
    func run() {
        /// 주어진 숫자가 소수인지 판별하는 함수
        /// - Parameter number: 검사할 정수
        /// - Returns: 소수이면 `true`, 아니면 `false`
        func isPrime(_ number: Int) -> Bool {
            if number <= 1 {    // 1 이하의 숫자는 소수가 아님
                return false
            }
            if number <= 3 {    // 2, 3은 소수
                return true
            }
            
            var i = 2
            while i * i <= number {     // √N까지만 검사 (O(√N))
                if number % i == 0 {    // 약수가 존재하면 소수가 아님
                    return false
                }
                i += 1
            }
            return true
        }

        // 입력 받기
        if let n = Int(readLine() ?? "0"),  // 첫 줄: 숫자의 개수 N
           let numbers = readLine()?.split(separator: " ").compactMap({ Int($0) }) { // 두 번째 줄: 공백으로 구분된 숫자들
            
            var primeCount = 0  // 소수 개수 저장 변수
            
            // 입력받은 숫자들을 순회하면서 소수인지 확인
            for number in numbers {
                if isPrime(number) {    // 소수이면 개수 증가
                    primeCount += 1
                }
            }
            
            // 최종 소수 개수 출력
            print(primeCount)
        }
    }
}
