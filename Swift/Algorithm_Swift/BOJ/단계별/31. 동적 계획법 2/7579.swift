//
//  7579.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/4/25.
//

//  문제 링크: https://www.acmicpc.net/problem/7579
//  알고리즘 분류: 다이나믹 프로그래밍, 배낭 문제

class BOJ7579: Solvable {
    // 메모리: 79512KB, 시간: 28ms, 코드 길이: 610B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()
        let M = fileIO.readInt()

        var memory = [Int](repeating: 0, count: N)
        var cost = [Int](repeating: 0, count: N)

        for i in 0..<N {
            memory[i] = fileIO.readInt()
        }
        for i in 0..<N {
            cost[i] = fileIO.readInt()
        }

        let MAX_COST = cost.reduce(0, +)
        var dp = [Int](repeating: 0, count: MAX_COST + 1)

        for i in 0..<N {
            for j in stride(from: MAX_COST, through: cost[i], by: -1) {
                dp[j] = max(dp[j], dp[j - cost[i]] + memory[i])
            }
        }

        for c in 0...MAX_COST {
            if dp[c] >= M {
                print(c)
                break
            }
        }
    }
}
