//
//  2618.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/10/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2618
//  알고리즘 분류: 다이나믹 프로그래밍, 역추적

class BOJ2618: Solvable {
    // 메모리: 88324KB, 시간: 168ms, 코드 길이: 2306B
    func run() {
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()
        let W = fileIO.readInt()

        var r = [Int](repeating: 0, count: W + 1)
        var c = [Int](repeating: 0, count: W + 1)
        for i in 1...W {
            r[i] = fileIO.readInt()
            c[i] = fileIO.readInt()
        }

        let size = W + 1
        func id(_ i: Int, _ j: Int) -> Int { i * size + j }

        var dp = [Int](repeating: -1, count: size * size)
        var choice = [UInt8](repeating: 0, count: size * size)

        func distFrom(_ last: Int, _ to: Int, _ car1: Bool) -> Int {
            let sr: Int, sc: Int
            if last == 0 {
                if car1 { sr = 1; sc = 1 } else { sr = N; sc = N }
            } else {
                sr = r[last]; sc = c[last]
            }
            return abs(sr - r[to]) + abs(sc - c[to])
        }

        func solve(_ i: Int, _ j: Int) -> Int {
            let k = max(i, j) + 1
            if k > W { return 0 }
            let idx = id(i, j)
            if dp[idx] != -1 { return dp[idx] }
            let cost1 = distFrom(i, k, true)  + solve(k, j)
            let cost2 = distFrom(j, k, false) + solve(i, k)
            if cost1 <= cost2 {
                dp[idx] = cost1
                choice[idx] = 1
            } else {
                dp[idx] = cost2
                choice[idx] = 2
            }
            return dp[idx]
        }

        let minCost = solve(0, 0)
        var i = 0, j = 0
        var out = "\(minCost)\n"
        for _ in 1...W {
            let idx = id(i, j)
            let k = max(i, j) + 1
            if choice[idx] == 1 {
                out += "1\n"
                i = k
            } else {
                out += "2\n"
                j = k
            }
        }
        print(out, terminator: "")
    }
}
