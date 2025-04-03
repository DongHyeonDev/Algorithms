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
    // 메모리: 79508KB, 시간: 56ms, 코드 길이: 697B
    func run() {
        // 입력 받기
        if let input = readLine()?.split(separator: " ").compactMap({ Int($0) }), input.count == 2 {
            let m = input[0]
            let n = input[1]

            // 에라토스테네스의 체 초기화
            var isPrime = [Bool](repeating: true, count: n + 1)
            isPrime[0] = false
            isPrime[1] = false

            // √n 까지 배수 제거
            for i in 2...Int(sqrt(Double(n))) {
                if isPrime[i] {
                    var j = i * i
                    while j <= n {
                        isPrime[j] = false
                        j += i
                    }
                }
            }

            // 결과 출력
            for i in m...n {
                if isPrime[i] {
                    print(i)
                }
            }
        }

    }
}
