//
//  4948.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/4/25.
//

//  문제 링크: https://www.acmicpc.net/problem/4948
//  알고리즘 분류: 수학, 정수론, 소수 판정, 에라토스테네스의 체

import Foundation

class BOJ4948: Solvable {
    // 메모리: 80020KB, 시간: 24ms, 코드 길이: 583B
    func run() {
        // 최대 범위까지 소수를 구하기 위한 상수
        let maxN = 246_912
        var isPrime = [Bool](repeating: true, count: maxN + 1)
        isPrime[0] = false
        isPrime[1] = false

        // 에라토스테네스의 체로 소수 미리 구하기
        for i in 2...Int(sqrt(Double(maxN))) {
            if isPrime[i] {
                var j = i * i
                while j <= maxN {
                    isPrime[j] = false
                    j += i
                }
            }
        }

        // 여러 입력을 처리
        while let line = readLine(), let n = Int(line), n != 0 {
            let count = (n+1...2*n).filter { isPrime[$0] }.count
            print(count)
        }
    }
}
