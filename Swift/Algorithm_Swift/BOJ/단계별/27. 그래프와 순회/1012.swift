//
//  1012.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/6/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1012
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색, 격자 그래프, 플러드 필

class BOJ1012: Solvable {
    // 메모리: 79652KB, 시간: 12ms, 코드 길이: 1415B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 상하좌우 이동 벡터
        let dx = [1, -1, 0, 0]
        let dy = [0, 0, 1, -1]

        // 테스트케이스 수
        let T = fileIO.readInt()
        for _ in 0..<T {
            // 지도의 가로(M), 세로(N), 배추 개수(K)
            let M = fileIO.readInt()
            let N = fileIO.readInt()
            let K = fileIO.readInt()

            // 배추가 심어진 곳만 true로 표시
            var grid = [[Bool]](
                repeating: [Bool](repeating: false, count: M),
                count: N
            )

            for _ in 0..<K {
                let x = fileIO.readInt()
                let y = fileIO.readInt()
                grid[y][x] = true
            }

            var wormCount = 0

            // BFS를 위한 큐(배열+인덱스)
            for y in 0..<N {
                for x in 0..<M {
                    // 아직 방문하지 않은 배추가 있으면 새 군집 발견
                    if grid[y][x] {
                        wormCount += 1
                        // BFS 시작
                        var queue = [(y, x)]
                        grid[y][x] = false
                        var idx = 0

                        while idx < queue.count {
                            let (cy, cx) = queue[idx]
                            idx += 1
                            for d in 0..<4 {
                                let ny = cy + dy[d]
                                let nx = cx + dx[d]
                                if ny >= 0 && ny < N && nx >= 0 && nx < M && grid[ny][nx] {
                                    grid[ny][nx] = false
                                    queue.append((ny, nx))
                                }
                            }
                        }
                    }
                }
            }

            // 결과 출력
            print(wormCount)
        }
    }
}
