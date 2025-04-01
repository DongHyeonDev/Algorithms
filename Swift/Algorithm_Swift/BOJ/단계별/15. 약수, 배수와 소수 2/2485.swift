//
//  2485.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/1/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2485
//  알고리즘 분류: 수학, 정수론, 유클리드 호제법

class BOJ2485: Solvable {
    // 메모리: 82608KB, 시간: 52ms, 코드 길이: 1032B
    func run() {
        // 최대공약수(GCD)를 구하는 함수 (유클리드 호제법)
        func gcd(_ a: Int, _ b: Int) -> Int {
            var num1 = a
            var num2 = b
            while num2 != 0 {
                let temp = num2
                num2 = num1 % num2
                num1 = temp
            }
            return num1
        }

        // 입력 받기
        if let n = Int(readLine() ?? "") {
            var positions = [Int]()
            
            // 가로수 위치 입력
            for _ in 0..<n {
                if let value = Int(readLine() ?? "") {
                    positions.append(value)
                }
            }
            
            // 인접한 가로수들 간의 간격 계산
            var diffs = [Int]()
            for i in 1..<positions.count {
                diffs.append(positions[i] - positions[i - 1])
            }

            // 모든 간격들의 최대공약수 계산
            var currentGCD = diffs[0]
            for i in 1..<diffs.count {
                currentGCD = gcd(currentGCD, diffs[i])
            }

            // 각 구간마다 필요한 나무 개수 계산 후 합산
            var result = 0
            for diff in diffs {
                result += (diff / currentGCD - 1)
            }

            print(result)
        }
    }
}
