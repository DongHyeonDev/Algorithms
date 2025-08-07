//
//  14002.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/7/25.
//

//  문제 링크: https://www.acmicpc.net/problem/14002
//  알고리즘 분류: 다이나믹 프로그래밍, 역추적

class BOJ14002: Solvable {
    // 메모리: 79512KB, 시간: 12ms, 코드 길이: 762B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        var a = [Int](repeating: 0, count: n)
        for i in 0..<n {
            a[i] = fileIO.readInt()
        }

        var dp = [Int](repeating: 1, count: n)
        var prev = [Int](repeating: -1, count: n)

        for i in 0..<n {
            for j in 0..<i {
                if a[j] < a[i], dp[j] + 1 > dp[i] {
                    dp[i] = dp[j] + 1
                    prev[i] = j
                }
            }
        }

        var lisLength = 0
        var lastIndex = -1
        for i in 0..<n {
            if dp[i] > lisLength {
                lisLength = dp[i]
                lastIndex = i
            }
        }

        var result = [Int]()
        var current = lastIndex
        while current != -1 {
            result.append(a[current])
            current = prev[current]
        }
        result.reverse()

        print(lisLength)
        print(result.map { String($0) }.joined(separator: " "))
    }
}
