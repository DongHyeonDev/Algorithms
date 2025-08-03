//
//  2293.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/3/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2293
//  알고리즘 분류: 다이나믹 프로그래밍

class BOJ2293: Solvable {
    // 메모리: 79512KB, 시간: 28ms, 코드 길이: 494B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()
        let k = fileIO.readInt()
        var coins = [Int](repeating: 0, count: n)
        for i in 0..<n {
            coins[i] = fileIO.readInt()
        }

        var dp = [Int](repeating: 0, count: k + 1)
        dp[0] = 1

        for coin in coins {
            if k >= coin {
                for amount in coin...k {
                    dp[amount] += dp[amount - coin]
                    if dp[amount] >= 2_147_483_648 {
                        dp[amount] = 0
                    }
                }
            }
        }

        print(dp[k])
    }
}
