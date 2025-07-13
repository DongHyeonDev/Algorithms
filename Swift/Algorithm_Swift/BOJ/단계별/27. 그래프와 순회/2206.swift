//
//  2206.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/13/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2206
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 격자 그래프

class BOJ2206: Solvable {
    // 메모리: 214148KB, 시간: 440ms, 코드 길이: 1493B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt(), M = fileIO.readInt()

        // 맵 입력
        var grid = Array(repeating: [Int](), count: N)
        for i in 0..<N {
            let line = fileIO.readString()  // readString() 이용
            grid[i] = line.utf8.map { Int($0 - 48) }
        }

        // 3차원 방문 배열: visited[i][j][b] = i,j에 b번(0/1)만큼 벽을 부수고 왔는지
        var visited = Array(
            repeating: Array(repeating: [false, false], count: M),
            count: N
        )

        // BFS 큐: (i, j, breakCount)
        var queue: [(i: Int, j: Int, b: Int)] = []
        var head = 0

        // 시작
        visited[0][0][0] = true
        queue.append((0, 0, 0))
        var steps = 1

        let dirs = [(1,0),(-1,0),(0,1),(0,-1)]
        var found = false

        // 레벨별 BFS
        while head < queue.count && !found {
            let levelSize = queue.count - head
            for _ in 0..<levelSize {
                let (i, j, b) = queue[head]; head += 1
                if i == N-1 && j == M-1 {
                    print(steps)
                    found = true
                    break
                }
                for (di, dj) in dirs {
                    let ni = i + di, nj = j + dj
                    guard ni >= 0 && ni < N && nj >= 0 && nj < M else { continue }
                    if grid[ni][nj] == 0 && !visited[ni][nj][b] {
                        visited[ni][nj][b] = true
                        queue.append((ni, nj, b))
                    }
                    else if grid[ni][nj] == 1 && b == 0 && !visited[ni][nj][1] {
                        // 벽 부술 기회 남아있으면
                        visited[ni][nj][1] = true
                        queue.append((ni, nj, 1))
                    }
                }
            }
            steps += 1
        }

        if !found {
            print(-1)
        }
    }
}
