//
//  1929.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/3/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1929
//  알고리즘 분류: 수학, 정수론, 소수 판정, 에라토스테네스의 체

import Foundation

class BOJ1929: Solvable {
    // 메모리: 80472KB, 시간: 64ms, 코드 길이: 428B
    func run() {
        // 공백으로 구분된 M, N 입력 받기
        let input = readLine()!.split(separator: " ").map { Int($0)! }
        let m = input[0]
        let n = input[1]

        // 0부터 n까지 소수 여부를 저장할 배열 생성, true로 초기화
        var isPrime = [Bool](repeating: true, count: n + 1)

        // 1은 소수가 아니므로 false로 지정 (0은 기본적으로 사용되지 않음)
        isPrime[1] = false

        // 에라토스테네스의 체 알고리즘: √n까지만 확인
        for i in 2..<Int(sqrt(Double(n)) + 1) {
            if isPrime[i] {
                var j = 2
                // i의 배수는 소수가 아님 → false로 마킹
                while i * j <= n {
                    isPrime[i * j] = false
                    j += 1
                }
            }
        }

        // m부터 n까지 범위 내의 소수 출력
        for i in m...n {
            if isPrime[i] {
                print(i)
            }
        }
    }
}
