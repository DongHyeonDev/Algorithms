//
//  1644.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/28/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1644
//  알고리즘 분류: 수학, 정수론, 두 포인터, 소수 판정, 에라토스테네스의 체

import Foundation

class BOJ1644: Solvable {
    // 메모리: 88892KB, 시간: 44ms, 코드 길이: 1792B
    func run() {
        /// 에라토스테네스의 체를 이용하여 n까지의 소수를 찾아 배열로 반환합니다.
        /// - Parameter n: 소수를 찾을 최대 자연수.
        /// - Returns: n까지의 소수들을 담은 정수 배열.
        func sieveOfEratosthenes(upTo n: Int) -> [Int] {
            guard n >= 2 else { return [] } // 2 미만은 소수가 없음

            var isPrime = [Bool](repeating: true, count: n + 1)
            isPrime[0] = false
            isPrime[1] = false

            var primes: [Int] = []
            for i in 2...n {
                if isPrime[i] {
                    primes.append(i)
                    for j in stride(from: i * 2, through: n, by: i) {
                        isPrime[j] = false
                    }
                }
            }
            return primes
        }

        /// 주어진 targetN을 연속된 소수들의 합으로 나타낼 수 있는 경우의 수를 계산합니다.
        /// - Parameters:
        ///   - targetN: 목표 자연수.
        ///   - primes: 소수들을 담은 배열 (오름차순).
        /// - Returns: targetN을 연속된 소수들의 합으로 나타낼 수 있는 경우의 수.
        func countContinuousPrimeSums(targetN: Int, primes: [Int]) -> Int {
            var start = 0
            var end = 0
            var currentSum = 0
            var count = 0

            // primes 배열이 비어있으면 0을 반환 (예: targetN이 1인 경우)
            guard !primes.isEmpty else { return 0 }

            while true {
                if currentSum >= targetN {
                    // 현재 합이 targetN보다 크거나 같으면 start 포인터를 이동하여 합을 줄임
                    currentSum -= primes[start]
                    start += 1
                } else if end == primes.count {
                    // end 포인터가 소수 배열의 끝에 도달하면 종료
                    break
                } else {
                    // 현재 합이 targetN보다 작으면 end 포인터를 이동하여 합을 늘림
                    currentSum += primes[end]
                    end += 1
                }

                // 현재 합이 targetN과 같으면 경우의 수 증가
                if currentSum == targetN {
                    count += 1
                }
            }
            return count
        }

        // 메인 실행 로직
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()

        // N까지의 소수 리스트 생성
        let primes = sieveOfEratosthenes(upTo: N)

        // 연속된 소수 합의 경우의 수 계산 및 출력
        let result = countContinuousPrimeSums(targetN: N, primes: primes)
        print(result)
    }
}
