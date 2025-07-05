//
//  2667.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/5/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2667
//  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색, 격자 그래프, 플러드 필

class BOJ2667: Solvable {
    // 메모리: 79516KB, 시간: 12ms, 코드 길이: 1457B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()

        // 입력 처리
        // N×N 지도 크기
        let N = fileIO.readInt()

        // 지도 데이터를 2차원 배열로 저장 ('0'→48, '1'→49)
        var grid = [[UInt8]](repeating: [], count: N)
        for i in 0..<N {
            grid[i] = fileIO.readByteSequenceWithoutSpaceAndLineFeed()
        }

        // 방문 여부
        var visited = [[Bool]](
            repeating: [Bool](repeating: false, count: N),
            count: N
        )

        // 상하좌우 방향 벡터
        let dx = [0, 0, 1, -1]
        let dy = [1, -1, 0, 0]

        var complexes = [Int]()

        // BFS로 단지 탐색
        for i in 0..<N {
            for j in 0..<N {
                // '1'이고 아직 방문하지 않았다면 새로운 단지
                if grid[i][j] == 49 && !visited[i][j] {
                    var queue = [(i, j)]
                    visited[i][j] = true
                    var head = 0
                    var count = 0

                    // BFS
                    while head < queue.count {
                        let (x, y) = queue[head]; head += 1
                        count += 1

                        for d in 0..<4 {
                            let nx = x + dx[d]
                            let ny = y + dy[d]
                            // 범위 안이고, 집('1')이며 방문 전이면
                            if nx >= 0 && nx < N && ny >= 0 && ny < N
                               && grid[nx][ny] == 49
                               && !visited[nx][ny] {
                                visited[nx][ny] = true
                                queue.append((nx, ny))
                            }
                        }
                    }
                    complexes.append(count)
                }
            }
        }

        // 결과 정렬 및 출력
        complexes.sort()
        print(complexes.count)
        for c in complexes {
            print(c)
        }
    }
}
