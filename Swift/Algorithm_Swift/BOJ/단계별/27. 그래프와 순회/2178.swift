//
//  2178.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/7/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2178
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 격자 그래프

class BOJ2178: Solvable {
    // 메모리: 80044KB, 시간: 20ms, 코드 길이: 1126B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력: N행 M열
        let N = fileIO.readInt()
        let M = fileIO.readInt()

        // 미로 정보: 1은 이동 가능, 0은 벽
        var maze = [[Int]](repeating: [Int](repeating: 0, count: M), count: N)
        for i in 0..<N {
            let line = fileIO.readString()
            for j in 0..<M {
                maze[i][j] = Int(line[line.index(line.startIndex, offsetBy: j)].asciiValue! - 48)
            }
        }

        // 상하좌우 이동 벡터
        let dx = [1, -1, 0, 0]
        let dy = [0, 0, 1, -1]

        // 거리 배열: 시작점에서 해당 칸까지의 최소 칸 수
        var dist = [[Int]](repeating: [Int](repeating: 0, count: M), count: N)
        // BFS 큐 (튜플 배열 + 인덱스)
        var queue = [(row: Int, col: Int)]()
        var qHead = 0

        // BFS 초기화: (0,0)에서 출발
        dist[0][0] = 1  // 시작 칸 포함
        queue.append((0,0))

        while qHead < queue.count {
            let (r, c) = queue[qHead]
            qHead += 1
            for d in 0..<4 {
                let nr = r + dy[d]
                let nc = c + dx[d]
                // 범위 검사 + 이동 가능 + 미방문
                if nr >= 0 && nr < N && nc >= 0 && nc < M &&
                   maze[nr][nc] == 1 && dist[nr][nc] == 0 {
                    dist[nr][nc] = dist[r][c] + 1
                    queue.append((nr,nc))
                }
            }
        }

        // (N-1, M-1) 칸까지의 거리 출력
        print(dist[N-1][M-1])
    }
}
