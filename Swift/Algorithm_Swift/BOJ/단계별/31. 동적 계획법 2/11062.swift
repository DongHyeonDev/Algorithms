//
//  11062.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/5/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11062
//  알고리즘 분류: 다이나믹 프로그래밍, 게임 이론

class BOJ11062: Solvable {
    // 메모리: 87568KB, 시간: 176ms, 코드 길이: 979B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let T = fileIO.readInt()

        for _ in 0..<T {
            let N = fileIO.readInt()
            var cards = [Int](repeating: 0, count: N)
            for i in 0..<N {
                cards[i] = fileIO.readInt()
            }

            var prefix = [Int](repeating: 0, count: N + 1)
            for i in 0..<N {
                prefix[i + 1] = prefix[i] + cards[i]
            }

            func rangeSum(_ l: Int, _ r: Int) -> Int {
                return prefix[r + 1] - prefix[l]
            }

            var dp = [[Int]](repeating: [Int](repeating: 0, count: N), count: N)

            for len in 1...N {
                for l in 0...(N - len) {
                    let r = l + len - 1
                    if l == r {
                        dp[l][r] = cards[l]
                    } else {
                        let total = rangeSum(l, r)
                        dp[l][r] = max(
                            cards[l] + (total - cards[l] - dp[l+1][r]),
                            cards[r] + (total - cards[r] - dp[l][r-1])
                        )
                    }
                }
            }

            print(dp[0][N - 1])
        }
    }
}
