//
//  1520.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 8/1/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1520
//  알고리즘 분류: 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 깊이 우선 탐색, 격자 그래프

class BOJ1520: Solvable {
    // 메모리: 86028KB, 시간: 36ms, 코드 길이: 845B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let M = fileIO.readInt()
        let N = fileIO.readInt()

        var map = [[Int]](repeating: [Int](repeating: 0, count: N), count: M)
        for i in 0..<M {
            for j in 0..<N {
                map[i][j] = fileIO.readInt()
            }
        }

        var dp = [[Int]](repeating: [Int](repeating: -1, count: N), count: M)
        let dx = [0, 0, -1, 1]
        let dy = [-1, 1, 0, 0]

        func dfs(_ y: Int, _ x: Int) -> Int {
            if y == M - 1 && x == N - 1 {
                return 1
            }

            if dp[y][x] != -1 {
                return dp[y][x]
            }

            dp[y][x] = 0

            for dir in 0..<4 {
                let ny = y + dy[dir]
                let nx = x + dx[dir]

                if ny < 0 || ny >= M || nx < 0 || nx >= N {
                    continue
                }

                if map[ny][nx] < map[y][x] {
                    dp[y][x] += dfs(ny, nx)
                }
            }

            return dp[y][x]
        }

        print(dfs(0, 0))
    }
}
